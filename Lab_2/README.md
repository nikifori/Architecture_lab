# Architecture_lab2  

## Δεύτερο εργαστήριο  
  
Σε αυτό το εργαστήριο ασχοληθήκαμε με την εκτέλεση μιας σειράς απο **benchmarks** στον **gem5**. Για τα benchmarks χρησιμοποιήσαμε ένα υποσύνολο των **SPEC cpu2006 benchmarks**.  

Τα **benchmarks** που χρησιμοποιήσαμε είναι τα εξής :  
  
  * **401.bzip2**
  * **429.mcf** 
  * **456.hmmer**
  * **458.sjeng**
  * **470.lbm**  
  
  Το configuration script που χρησιμοποιήσαμε για να τρέξουμε τα benchmarks είναι το ίδιο με αυτό της πρώτης εργαστηριακής άσκησης, δηλαδή το **se.py**.  

Επίσης, αυτά τα benchmarks τα τρέχουμε για συγκεκριμένο αριθμό εντολών(100000000) διότι για να εκτελεστούν πλήρως απαιτείται πάρα πολύ ώρα.

## Βήμα 1ο  

### Ερώτημα 1  

>CPU clock 2GHz

* Για το **401.bzip2** έχουμε :   

<h><p align='center'>
  <b>L1 instruction cache</b>
</p></h>  

![L1i](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step1/Q1/Spacebzip/2.png)

<h><p align='center'>
  <b>L1 data cache</b>
</p></h>  
  
![L1d](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step1/Q1/Spacebzip/4.png)

<h><p align='center'>
  <b>L2 cache</b>
</p></h>

![L2](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step1/Q1/Spacebzip/3.png)  

<h><p align='center'>
  <b>Cache line</b>
</p></h>

![cacheline](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step1/Q1/Spacebzip/5.png)  

* Για τα **429.mcf** , **456.hmmer**, **458.sjeng**, **470.lbm**  θα ισχύουν ακριβώς τα ίδια αποτελέσματα αφού τρέχουμε τα benchmarks με το ίδιο configuration script και με τις ίδιες παραμέτρους , **--cpu-type=MinorCPU, --caches, --l2cache**.  

### Ερώτημα 2  

>CPU clock 1GHz  

Benchmarks | sim time | CPI | L1d overall miss rate | L1i overall miss rate | L2 overall miss rate  
--- | --- | --- | --- | --- | ---  
401.bzip2 | 0.161337 | 1.613367 | 0.014683 | 0.000074 |	0.281702 |  
429.mcf | 0.109125 | 1.091249 | 0.002051 | 0.000037 |	0.724040 |  
456.hmmer | 0.118453 | 1.184534 | 0.001638 | 0.000205 |	0.082233 |  
458.sjeng | 0.704063 | 1.176363 | 0.001737 | 0.002895 |	0.987605 |  
470.lbm | 0.262355 | 3.528624 | 0.062568 | 0.000095 |	0.964146 |   

**εδω θα μπει το διαγραμμα- και τι παρατηρουμε** 

### Ερώτημα 3   

Σε αυτό το ερώτημα τρέχουμε τα benchmarks για συχνότητα επεξεργαστή **1GHz**. Βλέποντας τα αρχεία stats.txt από κάθε αρχείο παρατηρούμε τα εξής:  
  
Benchmarks | system.clk_domain.clock | system.cpu_clk_domain.clock | 
--- | --- | --- 
401.bzip2 | 1000 | 1000 
429.mcf | 1000 | 1000  
456.hmmer | 1000 | 1000 
458.sjeng | 1000 | 1000 
470.lbm | 1000 | 1000    

Όταν το τρέξαμε στο 1ο ερώτημα για **2GHz** είχαμε τα εξής:  

Benchmarks | system.clk_domain.clock | system.cpu_clk_domain.clock | 
--- | --- | --- 
401.bzip2 | 1000 | 500 
429.mcf | 1000 | 500  
456.hmmer | 1000 | 500 
458.sjeng | 1000 | 500 
470.lbm | 1000 | 500   

> 1000 σημαίνει (1T ticks)/(1000 clock period in ticks)=1GHz  
> 500 σημαίνει (1T ticks)/(500 clock period in ticks)=2GHz

Προφανώς τα αποτελέσματα θα είναι για όλα τα benchmarks ίδια αφού τα τρέχουμε ακριβώς με τα ίδια χαρακτηριστικά. Επίσης, για την δεύτερη περίπτωση βλέπουμε ότι το System clock είναι 1GHz και το CPU clock είναι 2GHz. Το System clock στην ουσία συχρονίζει όλα τα στοιχεία που βρίσκονται πάνω στην motherboard, πχ τον επεξεργαστή με την κύρια μνήμη(RAM) κτλ. Από την άλλη, το CPU clock είναι το ρολόι του επεξεργαστή και μόνο του επεξεργαστή και χρησιμοποιείται μόνο για τον συγχρονισμό μέσα στο τσιπάκι του επεξεργαστή. Σχεδόν πάντα το ρολόι του επεξεργαστή είναι αρκετά μεγαλύτερο απο το System clock. Επίσης, αν προσθέσουμε έναν ακόμα επεξεργαστή η λογική λέει ότι θα είναι στην ίδια συχνότητα με τον επεξεργαστή που είχαμε ήδη.Τέλος, παρατηρώντας τους χρόνους εκτέλεσης του κάθε benchmark για τις δύο διαφορετικές συχνότητες έχουμε τον εξής πίνακα:  

Benchmarks | 1GHz | 2GHz | 
--- | --- | --- 
401.bzip2 | 0.161337 | 0.084159 
429.mcf | 0.109125 | 0.055477  
456.hmmer | 0.118453 | 0.059368 
458.sjeng | 0.704063 | 0.513541 
470.lbm | 0.262355 | 0.174681   

Σε μερικά benchmarks έχουμε αρκετά καλό scaling σε αλλά όπως το **458.sjeng** και το **470.lbm** όχι και τόσο. Αυτό συμβαίνει γιατί από μία συχνότητα και μετά (ανάλογα και το benchmark) ο επεξεργαστής ουσιαστικά επείδη είναι ερκετά πιο γρήγορος απο τα επιμέρους στοιχεία (πχ κύρια μνήμη), **"περιμένει"**.Άρα όσο και να μεγαλώνουμε πχ επί 2 τη συχνότητα του επεξεργαστή, ο χρόνος που θα χρειαστεί το πρόγραμμα για να τελειώσει δε θα υποδιπλασιαστεί.  

## Βήμα 2ο





## Βιβλιογραφία  

https://cs.stackexchange.com/questions/32149/what-are-system-clock-and-cpu-clock-and-what-are-their-functions
  
  








