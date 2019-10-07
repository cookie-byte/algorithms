#include <iostream>
using namespace std;
class String
{
private:
  char *strArray;
  int length;
public:
    String ()
  {
    strArray= NULL;
    length=0;
  }
  String (char *char_arr)
  {
    if (char_arr == NULL)
      {
	strArray = nullptr;
	return;
      }
    int count=0;
    char *p =char_arr;
    while (*p != '\0')
      {
	count++;
    p++;
      }
    length=count;
    strArray = new char[count + 1];
    for (int i = 0; i < count; i++)
      {
	strArray[i] = char_arr[i];
      }
    strArray[count]='\0';
  }
  String (int len)
  {
    length = len;
    strArray = new char[len + 1];
  }

  String (String &ob1)
  {
    cout<<"copy constructor";
    int l=getLength();
    ob1.strArray = new char[l + 1];
    for(int i=0;i<l;i++){
        ob1.strArray[i]=strArray[i];
    }
    ob1.strArray[l]='\0';
    ob1.length = l; 
  }

  
  void printString()
  {
    cout << strArray << endl;
  }

  void set_string (char *st)
  {
    int len=getLength();
    strArray = new char[len +1];
    for(int i=0; i < len;i++){
        strArray[i]=st[i];
    }
    strArray[len]='\0';
  }

  char *get_string()
  {
    return strArray;
  }


  String operator+ (String const &Ob1)
  {
    String obj3;
    char *s=new char[length+Ob1.length+1];
    int j=0;
    while (strArray[j]!='\0'){
      s[j]=strArray[j];
      j++;
    }
    while (Ob1.strArray[j-length]!='\0'){
      s[j]=Ob1.strArray[j-length];
      j++;
    }
    s[j]='\0';
    obj3.strArray=s;
    obj3.length=length+Ob1.length;
    return obj3;}
    char &operator[](int index){
        return strArray[index];
    }
    int getLength(){
        return length;
    }

};

int main(){
    String st1;
    char s1[100];
    cout<<"enter first string\n";
    cin>>s1;
    char s2[100];
    cout<<"enter second string\n";
    cin>>s2;
    String opp1(s1);
    String opp(s2);
    st1 = opp1 + opp;
    cout<<"concatenated string "<<st1.get_string()<<endl;
    int co[26];
    for (int k=0;k<26;k++){
      co[k]=0;
    }
    for (int k=0;k<st1.getLength();k++){
      co[st1[k]-'a']+=1;
    }
    int most=0,ind=-1;
    for (int i=0;i<26;i++){
      if (co[i]>most){
        most=co[i];
        ind=i;
      }
    }
    cout<<"string after removal most occuring character\n";
    for (int m=0;m<st1.getLength();m++){
      if (st1[m]-'a'!=ind){
        cout<<st1[m];
      }
    }
    cout<<'\n';
    return 0;
}