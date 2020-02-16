/*
Kysymys "Kuinka monessa yhtenäisessä bittijonon osajonossa on parillinen määrä ykkösbittejä?"
on yhtäpitävä kysymyksen
"Kuinka monta parillisen summan alitaulukkoa on bittijonosta muodostuvassa taulukossa?".
Tämä johtuu siitä, että ykkösbittien määrä alitaulukossa on sama kuin alitaulukon summa.

Tehtävää voi lähteä ratkaisemaan täydellisellä haulla kolmella tai kahdella loopilla,
mutta täysiin pisteisiin vaadittiin ratkaisu, joka on selvästi nopeampi. Tässä
tiedostossa on vastausesimerkki täysiin pisteisiin.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int n;

string s;

/*Syötemerkkijono voi olla pitkä, jolloin alitaulukoita on paljon, joten
tulee käyttää suurempien lukujen muuttujia  oikean vastauksen takaamiseksi*/

long long sum; //Lasketaan tähän kertyvä summa kun merkkijono käydään kertaalleen läpi

/*Alustetaan muuttujat jotka laskevat, moniko merkkijonon eri kohdista päättää alusta alkavan
alitaulukon niin, että tämän alitaulukon summa on parillinen tai pariton.
Myös tyhjä alitaulukko lasketaan parilliseksi.*/

long long evens=1, odds;

//Tähän lopullinen vastaus
long long ans;
 
int main(){
    //Luetaan syöte
    cin>>s;
 
    //Merkataan apumuuttujalla n merkkijonon pituutta

    n = s.length();
 
    //Käydään merkkijonon merkit yksitellen läpi

    for(int i=0; i<n; i++){

        //Jos käsiteltävä merkki on 1, kertyvä summa kasvaa yhdellä

        if(s[i] == '1')sum++;

        /*Jos kertyvä summa on tällä hetkellä parillinen, kasvatetaan parillisten määrää yhdellä,
        muutoin parittomien määrä kasvaa yhdellä*/
 
        if(sum % 2 == 0)evens++;
        else odds++;
    }

    /*
    Kaikki alitaulukot muodostuvat alkukohdasta ja päätepisteestä.
    Alitaulukon summa on S_loppu - S_(alku-1), jossa S_i kertoo alusta alkavan ja
    kohtaan i päättyvän kertyneen summan.

    On kaksi tapausta, jolloin kahden kokonaisluvun erotus tai summa on parillinen:
    1)operoitavat luvut ovat molemmat parillisia
    2)operoitavat luvut ovat molemmat parittomia

    Siispä voidaan selvittää, monellako eri tavalla parillisten kohtien joukosta
    voidaan valita alitaulukon alku ja loppu, jolloin myös alitaulukon summa on
    parillinen.

    Vastaavasti vastauksessa tulee myös huomioida alitaulukot, joissa alitaulukon alku- ja
    loppukehdissä summakertymä on pariton, jolloin alitaulukon summa on parillinen.

    Binomikertoimen kaavalla "n yli k:n" voidaan johtaa kaava sille, monellako tapaa n alkiosta
    voidaan valita 2: n*(n-1)/2.

    Summataan vastaukseen siis eri tavat valita alitaulukon alku-ja loppukohta niin, että
    alun ja lopun summakertymien parillisuus on sama.
    */
 
    ans += evens*(evens-1)/2;
    ans += odds*(odds-1)/2;
 

    //Tulostetaan vastaus
    cout<<ans<<"\n";
 
 
    return 0;
}