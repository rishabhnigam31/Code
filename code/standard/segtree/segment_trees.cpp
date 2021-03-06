#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef struct Tree{
       LL  add;
       LL  sum;
       LL  num;
}Tree;

Tree F[1<<18];
Tree nullTree;
LL N,Q;
Tree merge(Tree a,Tree b)
{
	Tree temp;
	temp.sum=a.sum+b.sum;
	temp.add=0;
	temp.num=a.num+b.num;
	return temp;
}

void init()
{
	for (LL  i =(1<<18)-1 ; i>=1<<17 ; i--)
		{F[i].sum=0;F[i].add=0;F[i].num=1;}
	for(LL  i=(1<<17)-1;i>0;i--)
		F[i]=merge(F[2*i],F[2*i +1]);
}

void update(LL  root,LL  leftrange,LL  rightrange, LL  i, LL  j,LL  v)
{
	if(i<=leftrange && j>=rightrange)
	{
		F[root].add += v;
		F[root].sum = F[root].sum + F[root].num*v; 
		return;
	}
	LL l=2*root,r=l+1,mid=(leftrange+rightrange)/2;
	Tree a=nullTree,b=nullTree;
	if(i<mid) update(l,leftrange,mid,i,j,v);
	if(j>mid) update(r,mid,rightrange,i,j,v);
	LL f=F[root].add;
	F[root]=merge(F[l],F[r]);
	if(f){
		   F[root].add=f;
		   F[root].sum=F[root].sum+ F[root].num*f;
    }
	
}

Tree query(LL  root,LL  leftrange,LL  rightrange,LL  i,LL  j)
{
	if(i<=leftrange && j>=rightrange){
               return F[root];
       }
	LL  l=2*root,r=l+1,mid=(leftrange+rightrange)/2;
	Tree a=nullTree,b=nullTree;
	if(i<mid) a=query(l,leftrange,mid,i,j);
	if(j>mid) b=query(r,mid,rightrange,i,j);
	bool f=F[root].add;
	Tree ans=merge(a,b);
	if(f)
	{
		ans.add=f;
		ans.sum=ans.sum + ans.num*f;
	}
	return ans;
}

int main()
{
	nullTree.sum=0;nullTree.num=0;nullTree.add=0;
	LL N,Q,aa,bb,cc,jj,T;
	cin>>T;
	while(T--)
	{
		cin>>N>>Q;
		init();
		Tree answ;
		for(LL i=0;i<Q;i++)
		{
			scanf("%lld",&aa);
			if(aa==0){
				scanf("%lld%lld%lld",&bb,&cc,&jj);
				update(1,0,(1<<17),bb,cc+1,jj);
			}
			else {
			scanf("%lld%lld",&bb,&cc);
			answ=query(1,0,(1<<17),bb,cc+1);
			printf("%lld\n",answ.sum);
			}
//			for( aa=0;aa<3;aa++)
//				cout<<F[(1<<15)+aa].sum<<"      ";
//			cout<<endl;
//			for( aa=0;aa<5;aa++)
//				cout<<F[(1<<16)+aa].sum<<"  ";
//			cout<<endl;
//			for( aa=0;aa<10;aa++)
//				cout<<F[(1<<17)+aa].sum<<' ';
//			cout<<endl;
		}	
	}
return 0;
}

