class Solution {
public:
    bool winnerOfGame(string s) {
        bool ans=0;
        int a=0;
        int b=0;

        for(int i=1;i<s.size()-1;i++){
            if(s[i]==s[i-1] && s[i]==s[i+1]){
                if(s[i]=='A'){
                    a++;
                }
                else{
                    b++;
                }
            }
        }

        return a>b;
        
    }
};