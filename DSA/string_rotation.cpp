bool areRotations(string s1,string s2)
{
    // Your code here
    queue<char> q;
    int flag = 0;
    for(int j=0; s1[j]!='\0';j++){
        q.push(s1[j]);
    }
    
    for(int i=0 ; i<s1.length();i++){
        char a = q.front();
        q.pop();
        q.push(a);
        s1  = string::valueOf(q);
        if(s1==s2){
            flag =1;
            break;
        }
    }
    
    if(flag == 1){
        return 1;
    }
    else
        return 0;
    
}