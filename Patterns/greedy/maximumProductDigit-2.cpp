class Solution {
public:

    string freeSlotsFiller(int required, int length){
        string str;
        for(int digit = 9; digit >= 2; digit--){
            while(required % digit == 0){
                str.push_back(digit + '0');
                required /= digit;
            }
        }
        while(str.length() < length){
            str.push_back('1');
        }
        reverse(str.begin(), str.end());
        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();
        long long temp = t;

        for(int primeFact : {2, 3, 5, 7}){
            while(temp % primeFact == 0){
                temp /= primeFact;
            }
        }

        if(temp != 1) return "-1";
        vector<long long> remainingFactor(n + 1, t);
        for(int i = 0; i < n; i++){
            int digit = num[i] - '0';
            if(digit == 0){
                break;
            }
            remainingFactor[i + 1] = remainingFactor[i]/gcd(remainingFactor[i], (long long)digit);
        }

        int zeroPos = num.find('0');
        int zeroIdx = n - 1;
        if(zeroPos != -1){
            zeroIdx = zeroPos;
        }
        for(int i = zeroIdx; i >= 0; i--){
            long long required = remainingFactor[i];
            int freeSlots = n - 1 - i;
            int start = max(1, num[i] - '0');
            for(int digit = start; digit <= 9; digit++){
                long long furtherRequired = required / gcd(required, digit);
                string requiredNumber = freeSlotsFiller(furtherRequired, freeSlots);

                if(requiredNumber.length() == freeSlots){
                    return num.substr(0, i) + char(digit + '0') +  requiredNumber;
                }
            }
        }
        return freeSlotsFiller(t, n + 1);
    }
};