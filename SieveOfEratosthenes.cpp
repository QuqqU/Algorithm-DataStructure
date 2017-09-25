   
   bool notprime[10005]; // <- grobal value // false is prime
   
   
   notprime[1]=true;
    for(int i=2;i<=10000;i++){
        if(notprime[i]) continue;
        for(int j=i*2;j<=10000;j+=i)
            notprime[j]=true;
    }
