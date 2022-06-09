class Solution {
public:
    int tribonacci(int n) {  
        
        int Tk, Tk1, Tk2, Tk3;

        Tk =  0;
        Tk1 = 1;
        Tk2 = 1;

        if (n <= 1) return n;
            
        for(int i = 2; i < n; i++){
            Tk3 = Tk + Tk1 + Tk2;
            Tk = Tk1;
            Tk1 = Tk2;
            Tk2 = Tk3 ;
        }
        return Tk2;
    }
};