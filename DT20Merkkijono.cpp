/*Kisakoodauksessa tiiviys ja nopeus ovat eduksi, alla oleva headeri
sisällyttää kattavan standardikirjaston yhdellä rivillä usean eri headerin
sijaan*/

#include <bits/stdc++.h>
 
using namespace std;
 
int n;
 
/*Selvitin ensin paperille hahmotellen jonkin merkkijonopätkän, 
jota voi toistaa loputtomiin niin, että se täyttää tehtävänannon ehdot*/

string ans="71315131";
 
int main(){

	//Luetaan syöte eli merkkijonon pituus

    cin>>n;
 
 	//Tulostetaan n merkkiä (eli pyydetyn pituinen merkkijono)

    for(int i=0; i<n; i++){

    	/*Moduloa hyödyntäen voidaan merkkijonosta ans lukea merkkejä
    	vaikka n olisi suurempi kuin ans:in pituus*/

        cout<<ans[i % ans.length()];
    }
    cout<<"\n"; //Tulosteeseen rivinvaihto selkeyden vuoksi
 
    return 0;
}