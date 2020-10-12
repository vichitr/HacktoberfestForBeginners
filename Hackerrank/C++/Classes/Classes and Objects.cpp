class Student{
    private:
        vector <int> score;
    public:
        void input(){
           for(int i=0; i<5; i++)
           {
               int s;
               cin>>s;
               score.push_back(s);
           }
        }
    int calculateTotalScore(){
        int sum=0;
        for(int i=0; i<5; i++)
            sum+=score[i];
        return sum;
        
    }
};
