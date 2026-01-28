#include <iostream>
#include <string>
using namespace std;    
class calculator{
    private:
        double num1 , num2;
    public:
       void inputdata(double a, double b){
        num1=a;
        num2=b;
      }
       double Addition(){
        return num1+num2;
          }
       double Subtraction(){
        return num1 - num2;

        }
       double Multiply(){
        return num1*num2;
         }
       double Division(){
             if(num2!=0){
                 return num1/num2;
             }else{std::cout << " Zero Devision Error......! ";
                    return 0; }
                }
};
int main(){
    calculator calc;
    double a , b;
    cout << "Enter Two Number To Calculate: ";
    cin >> a >> b;
    cout<<endl;
    calc.inputdata(a,b);
    int ch=1;
    int s;
    while(ch==1){
        cout << "Enter Operation Sign(1: + ,2: - ,3: * ,4: / ) : ";
        cin >> s ;
        cout<<endl;
        switch (s){
            case 1 :
                cout <<"Addition Of "<<a<<" and "<<b<<" is :"<<calc.Addition()<<endl;
                cout<<endl;
                break;
            case 2 :
                cout <<"Subtraction Of "<<a<<" and "<<b<<" is :"<<calc.Subtraction()<<endl;
                cout<<endl;
                break;
            case 3 :
                cout <<"Multiply Of "<<a<<" and "<<b<<" is :"<<calc.Multiply()<<endl;
                cout<<endl;
                break;
            case 4 :
                cout <<"Divition Of "<<a<<" and "<<b<<" is :"<<calc.Division()<<endl; 
                cout<<endl; 
                break; 
            default:
                cout<<endl;
                cout <<"Invalid Operation Sign...!"<<endl;
        }
        int v;
        cout<<"Enter 1 to repeat the operation or 0 to end : ";
        cin >> v;
        if(v!=1){
            ch++;
            break;
        }else{
            cout<<endl;
            cout<<"Here We Go.....!"<<endl;
        }
    }
}
