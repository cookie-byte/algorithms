#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<unsigned int> build_table(string pat){
vector<unsigned int> table(pat.size(),-1);
unsigned int i=0,j=i+1;
table[i] = 0;
while(j<pat.size()){

if(pat[i] == pat[j]){
	table[j] = i + 1;
i++;
j++;
}
else if(i != 0){

i = table[--i];

}
else{
table[j] = 0 ;
j++;
}

}

return table;
}


vector<unsigned int> kmp_search(string text,string pat){
vector<unsigned int> table=build_table(pat);
unsigned int ind=-1,j=0,i=0;
vector<unsigned int>indexes;
while(i<text.size()){
if(text[i] == pat[j])
{
i++;
j++;
if(pat.size()==j){
	ind=i-j;
indexes.push_back(ind);
j = table[j-1];
}
}
else if(j!=0)
{

j=table[j];

}
else
{

i++;
}

}
return indexes;
}
int main(){
	string text;
	string pat;
	getline(cin,text);
	getline(cin,pat);
	vector<unsigned int>indexes = kmp_search(text,pat);
	for(unsigned x:indexes)
	cout<<pat<<" is at "<<x<<endl;
	if(indexes.size()==0)
		cout<<"Pattern Not Found\n";
i	return 0;
}
