class Solution {
public:
    
    string solve(int &n){
        if(n>=1000){
            n-=1000;return "M";
        }
        if(n<1000 && n>=900){
            n-=900;return "CM";
        }
        if(n>=500){
            n-=500;return "D";
        }
        if(n<500 && n>=400){
            n-=400;return "CD";
        }
        if(n>=100){
            n-=100;return "C";
        }
        if(n<100 && n>=90){
            n-=90;return "XC";
        }
        if(n>=50){
            n-=50;return "L";
        }
        if(n<50 && n>=40){
            n-=40;return "XL";
        }
        if(n>=10){
            n-=10;return "X";
        }
        if(n<10 && n>=9){
            n-=9;return "IX";
        }
        if(n>=5){
            n-=5;return "V";
        }
        if(n<5 && n>=4){
            n-=4;return "IV";
        }
        else{
            n-=1;return "I";
        }
    }
    
    string intToRoman(int num) {
        string ans = "";
        while(num!=0){
            ans += solve(num);
        }
        return ans;
    }
};