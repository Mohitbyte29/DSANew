class Solution {
    int arrivalAlice(string aA, unordered_map<string, int> mp){
        string res = "";
        for(int i = 0; i < 2; i++){
            res += aA[i];
        }
        int num1 = mp[res];
        string day = "", day2 = "";
        for(int i = 3; i < 5; i++){
            day += aA[i];
        }
        num1 += stoi(day);
        return num1;
    }
    int arrivalBob(string aB, unordered_map<string, int> mp){
        string res2 = "";
        for(int i = 0; i < 2; i++){
            res2 += aB[i];
        }
        int num2 = mp[res2];
        string day2 = "";
        for(int i = 3; i < 5; i++){
            day2 += aB[i];
        }
        num2 += stoi(day2);
        return num2;
    }
    int departureAlice(string lA, unordered_map<string, int> mp){
        string res = "";
        for(int i = 0; i < 2; i++){
            res += lA[i];
        }
        int num1 = mp[res];
        string day = "";
        for(int i = 3; i < 5; i++){
            day += lA[i];
        }
        num1 += stoi(day);
        return num1;
    }
    int departureBob(string lB, unordered_map<string, int> mp){
        string res2 = "";
        for(int i = 0; i < 2; i++){
            res2 += lB[i];
        }
        int num2 = mp[res2];
        string day2 = "";
        for(int i = 3; i < 5; i++){
            day2 += lB[i];
        }
        num2 += stoi(day2);
        return num2;
    }
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {
        unordered_map<string, int> mp = {{"01", 0}, {"02", 31}, {"03", 59}, {"04", 90}, {"05", 120}, {"06", 151}, {"07", 181}, {"08", 212}, {"09", 243}, {"10", 273}, {"11", 304}, {"12", 334}};
        int aliceArrival = arrivalAlice(aA, mp);
        int bobArrival = arrivalBob(aB, mp);
        int aliceDep = departureAlice(lA, mp);
        int bobDep = departureBob(lB, mp);
        if(aliceDep < bobArrival || bobDep < aliceArrival) return 0;
        if(aliceArrival < bobArrival){
            if(aliceDep <= bobDep){
                return (aliceDep - bobArrival + 1);
            }
            else{
                return (bobDep - bobArrival + 1);
            }
        } 
        else if (aliceArrival >= bobArrival){
            if(aliceDep >= bobDep){
                return (bobDep - aliceArrival + 1);
            }
            else{
                return (aliceDep - aliceArrival + 1);
            }
        }
        return 0;
    }
};