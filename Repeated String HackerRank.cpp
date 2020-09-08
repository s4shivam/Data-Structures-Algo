// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    if(s.length()==0 || (s.length()==1 && s[0]!='a') ){
        return 0;
    }
    if(s.length()==1 && s[0]=='a'){
        return n;
    }
    long int fullrepeat = 0;
    long int count;
    long int AcountInString = 0;
    long int remainderString  = 0;
    for(char c:s){
        if(c=='a'){
            AcountInString++;
        }
    }
    fullrepeat = n/(s.length());    //10/3 = 3;
    count += fullrepeat * AcountInString;
    remainderString = n % s.length(); //10%3  =  1;
    for(long int i=0;i<remainderString;i++){
        if(s[i]=='a'){
            count++;
        }
    }
    return count;
    
}
