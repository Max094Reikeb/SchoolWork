// exo 1 
function fibo(n) {
    var u0=1;
    var u1=1;
    var res,i;
    for(i=2;i<=n;i++){
      res=u1+u0;
      u0=u1;
      u1=res;
    }
    return res;
}