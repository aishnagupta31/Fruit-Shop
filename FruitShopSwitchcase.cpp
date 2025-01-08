#include<iostream>
using namespace std;
class fruit{
    private:
    string name;
    public:
    // fruit(){}
    fruit(string name){
        this->name=name;
    }
};
class fruitingms: public fruit{
    private:
    double available_kgs;
    double price_per_kg;
    public:
    fruitingms(string name,double available_kgs,double price_per_kg):fruit(name){
        this->available_kgs=available_kgs;
        this->price_per_kg= price_per_kg;
    }
    bool checkAvailability(double need){
        if(need > available_kgs){
            return false;
        }
        else{
            return true;
        }
    }
    void updateAvailability(double need){
        available_kgs=available_kgs-need;
    }
    double getavailable_kg(){
        return available_kgs;
    }
    double getpriceperkg(){
        return price_per_kg;
    }
};
class fruitinpcs: public fruit{
    private:
    int available_pcs;
    double price_per_pc;
    public:
    fruitinpcs(string name,int available_pcs,double price_per_pc):fruit(name){
        this->available_pcs=available_pcs;
        this->price_per_pc= price_per_pc;
    }
    bool checkAvailability(double need){
        if(need > available_pcs){
            return false;
        }
        else{
            return true;
        }
    }
    void updateAvailability(double need){
        available_pcs=available_pcs-need;
    }
    int getavailable_pcs(){
        return available_pcs;
    }
    double getpriceperpc(){
        return price_per_pc;
    }
};
class sale{
    private:
    fruitingms *fgms= NULL;
    fruitinpcs *fpcs= NULL;
    double unit;
    double amount;
    public:
    sale(fruitingms *fgms, double unit){
        this->fgms=fgms;
        this->unit=unit;
    }
    sale(fruitinpcs *fpcs, int unit){
        this->fpcs=fpcs;
        this->unit=unit;
    }
    double bill(){
        if(fgms!=NULL){
            amount = unit * fgms->getpriceperkg();
            fgms->checkAvailability(unit);
        }
        if(fpcs!=NULL){
            amount = unit * fpcs->getpriceperpc();
            fpcs->checkAvailability(unit);
        }
        if(amount>=500){
            amount = discount();
        }
        return amount;
    }
    double discount(){
        amount = amount - (amount * 0.05);
        return amount;
    }
};
int main(){
    cout<<"Enter 1 to buy fruits in kgs\n";
    cout<<"Enter 2 to buy fruits in pieces\n";
    cout << "Enter 3 to exit\n" ;
    bool running = true;
    while(running){
        int z;
        cin>>z;
        switch(z){
            case 1: {
            string nameofFruit;
            cout<<"Enter the name of the fruit you have to purchase in grams : ";
            cin>>nameofFruit;

            double avail;
            cout<<"Enter the availability of "<<nameofFruit<<" in grams or kgs : ";
            cin>>avail;

            double priceperkg;
            cout<<"Enter the price per kgs of "<<nameofFruit<<" : " ;
            cin>>priceperkg;
            
            fruitingms fgms(nameofFruit, avail, priceperkg);

            double unitingrams;
            cout<<"Enter the amount of "<<nameofFruit<<" you want to purchase in grams or kgs: ";
            cin>> unitingrams;

            cout<<fgms.checkAvailability(unitingrams);

            sale s1(&fgms,unitingrams);

            cout<<endl<<"The total amount which you have to pay is : "<<s1.bill()<<endl;
            break;
            }
            case 2: {
            string nameofFruit2;
            cout<<"\nEnter the name of the fruit you have to purchase in peices : ";
            cin>>nameofFruit2;

            int avail2;
            cout<<"Enter the availability of "<<nameofFruit2<<" in peices : ";
            cin>>avail2;

            double priceperpeice;
            cout<<"Enter the price per peice of "<<nameofFruit2<<" : " ;
            cin>>priceperpeice;

            fruitinpcs fpcs(nameofFruit2, avail2, priceperpeice);
            
            int unitinpeices;
            cout<<"Enter the amount of "<<nameofFruit2<<" you want to purchase in peices: ";
            cin>> unitinpeices;

            cout<<fpcs.checkAvailability(unitinpeices);

            sale s2(&fpcs,unitinpeices);

            cout<<endl<<"The total amount which you have to pay is : "<<s2.bill()<<endl;
            break;
            }
            case 3: running = false;
            break;
        }
    }
    return 0;
}