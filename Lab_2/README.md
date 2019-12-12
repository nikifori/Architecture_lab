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

![chart](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step1/Q2/Screenshot_1.png)

Από το γράφημα, είναι φανερό πως τα **benchmark**, _δεν παρουσιάζουν ίδια συμπεριφορά_. Αυτό που φαίνεται να ξεχωρίζει, **αρνητικά, ως προς τη απόδοση**, είναι το **470.lbm** , το οποίο έχει ακρετά **μεγαλύτερο cpi** από τα υπόλοιπα. H διαφορά αυτή, φαίνεται να οφείλεται στα μεγάλα **L1d_cache_miss_rate και L2_overall_miss_rate**. Κάτι ακόμα που ξεχωρίζει, είναι το **simulation time του 458.sjeng**, το οποίο είναι αρκετά μεγαλύτερο από τα υπόλοιπα. Τέλος, παρατηρείται σημαντικά _μεγαλύτερος_ αριθμός **L2_cache_misses απο L1_cache_misses**.

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

> CPU clock 1GHz  

Η **διαδικασία επιλογής** των χαρακτηριστηκών του συστήματος, λόγο των πολλών διαθέσιμων επιλογών, πρέπει να **περιοριστεί**. Προς αυτή την κατεύθυνση, **αξιοποιούμε** τα αποτελέσματα απο τα αρχεία **stats.txt , config.ini**. Βλέποντας τα **miss rates, αλλά και το cpi** για κάθε επιλογή, απορρίπτονται κάποιες τιμές. Για παράδειγμα, όταν παρατηρείται μεγάλος αριθμός miss rate στην **L2 Cache**, δοκιμάζουμε να αλλάξουμε το **μέγεθος** και το **assoc**. Σε περίπτωση που, οι αλλαγές, οδηγήσουν σε αύξηση του cpi, απορρίπτεται και η επιλογή της συγκεκριμένης τιμής, αλλά και η συγκεκριμένη διαδρομή, δηλαδή αν αυξήθηκη το cpi, όταν αυξάνουμε το L2 Cache size, τότε δεν δοκιμάζουμε να το αυξήσουμε καθόλου, και κοιτάμε μόνο την μείωση του. Στην περίπτωση που δυο επιλογές έχουν ίδιο αποτέλεσμα, αναλόγως την τιμή της μεταβλητής, αν είναι κοντά στα άνω και κάτω επιτρεπτά όρια, δεν συνεχίζουμε την διερεύνηση. Αργότερα, σε _κενό χρόνο_, υπολογίστηκαν και κάποια **"χαζά"** benchmarks, για την πληρότητα της εργασίας.
Όλα τα παραπάνω, αποτυπώνονται στα γραφήματα που ακολουθούν.  

* Για το **401.bzip2** έχουμε :  

<h><p align='center'>
  <b>Cacheline size</b>
</p></h>  

![Cacheline_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specbzip/Cacheline_size.png)  

<h><p align='center'>
  <b>L2 associativity</b>
</p></h>  

![L2_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specbzip/L2_assoc.png)  

<h><p align='center'>
  <b>L2 size</b>
</p></h>  

![L2_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specbzip/L2_size.png)  

<h><p align='center'>
  <b>L1 data cache associativity</b>
</p></h>  

![l1d_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specbzip/l1d_assoc.png)  

<h><p align='center'>
  <b>L1 data cache size</b>
</p></h>  

![l1d_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specbzip/l1d_size.png)  

<h><p align='center'>
  <b>L1 instruction cache associativity</b>
</p></h>  

![l1i_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specbzip/l1i_assoc.png)  

<h><p align='center'>
  <b>L1 instruction cache size</b>
</p></h>  

![l1i_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specbzip/l1i_size.png)  

* Για το **429.mcf** έχουμε :  

<h><p align='center'>
  <b>Cacheline size</b>
</p></h>  

![Cacheline_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specmcf/cacheline_size.png)  

<h><p align='center'>
  <b>L2 associativity</b>
</p></h>  

![L2_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specmcf/l2_assoc.png)  

<h><p align='center'>
  <b>L2 size</b>
</p></h>  

![L2_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specmcf/l2_size.png)  

<h><p align='center'>
  <b>L1 data cache associativity</b>
</p></h>  

![l1d_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specmcf/l1d_assoc.png)  

<h><p align='center'>
  <b>L1 data cache size</b>
</p></h>  

![l1d_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specmcf/l1d_size.png)  

<h><p align='center'>
  <b>L1 instruction cache associativity</b>
</p></h>  

![l1i_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specmcf/l1i_assoc.png)  

<h><p align='center'>
  <b>L1 instruction cache size</b>
</p></h>  

![l1i_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specmcf/l1i_size.png)  

* Για το **456.hmmer** έχουμε :  

<h><p align='center'>
  <b>Cacheline size</b>
</p></h>  

![Cacheline_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/spechmmer/Cacheline_size.png)  

<h><p align='center'>
  <b>L2 associativity</b>
</p></h>  

![L2_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/spechmmer/l2_assoc.png)  

<h><p align='center'>
  <b>L2 size</b>
</p></h>  

![L2_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/spechmmer/l2_size.png)  

<h><p align='center'>
  <b>L1 data cache associativity</b>
</p></h>  

![l1d_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/spechmmer/l1d_assoc.png)  

<h><p align='center'>
  <b>L1 data cache size</b>
</p></h>  

![l1d_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/spechmmer/l1d_size.png)  

<h><p align='center'>
  <b>L1 instruction cache associativity</b>
</p></h>  

![l1i_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/spechmmer/l1i_assoc.png)  

<h><p align='center'>
  <b>L1 instruction cache size</b>
</p></h>  

![l1i_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/spechmmer/L1i_size.png)  

* Για το **458.sjeng** έχουμε :  

<h><p align='center'>
  <b>Cacheline size</b>
</p></h>  

![Cacheline_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specjeng/cacheline_size.png)  

<h><p align='center'>
  <b>L2 associativity</b>
</p></h>  

![L2_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specjeng/l2_assoc.png)  

<h><p align='center'>
  <b>L2 size</b>
</p></h>  

![L2_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specjeng/l2_size.png)  

<h><p align='center'>
  <b>L1 data cache associativity</b>
</p></h>  

![l1d_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specjeng/l1d_assoc.png)  

<h><p align='center'>
  <b>L1 data cache size</b>
</p></h>  

![l1d_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specjeng/l1d_size.png)  

<h><p align='center'>
  <b>L1 instruction cache associativity</b>
</p></h>  

![l1i_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specjeng/l1i_assoc.png)  

<h><p align='center'>
  <b>L1 instruction cache size</b>
</p></h>  

![l1i_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/specjeng/l1i_size.png)  

* Για το **470.lbm** έχουμε :  

<h><p align='center'>
  <b>Cacheline size</b>
</p></h>  

![Cacheline_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/speclibm/Cacheline_size.png)  

<h><p align='center'>
  <b>L2 associativity</b>
</p></h>  

![L2_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/speclibm/l2_assoc.png)  

<h><p align='center'>
  <b>L2 size</b>
</p></h>  

![L2_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/speclibm/l2_size.png)  

<h><p align='center'>
  <b>L1 data cache associativity</b>
</p></h>  

![l1d_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/speclibm/l1d_assoc.png)  

<h><p align='center'>
  <b>L1 data cache size</b>
</p></h>  

![l1d_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/speclibm/l1d_size.png)  

<h><p align='center'>
  <b>L1 instruction cache associativity</b>
</p></h>  

![l1i_assoc](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/speclibm/l1i_assoc.png)  

<h><p align='center'>
  <b>L1 instruction cache size</b>
</p></h>  

![l1i_size](https://github.com/nikifori/Architecture_lab1/blob/master/Lab_2/Step2/Graphs/speclibm/l1i_size.png)  

## Βήμα 3ο

Σε αυτό το βήμα, πρέπει να υλοποιήσουμε μια συνάρτηση κόστους, και να πειράξουμε τις προδιαφραφές του επεξεργαστή μας, έτσι ώστε να βγάλουμε το καλύτερο performance per cost ratio (PPC). Η διαδικασία επιλογής παραμέτρων είναι αρκετά απλή. Ξεκινάμε με βάση τα configs για τη βέλτιστη λειτουργία από άποψη ταχύτητας (ελάχιστο CPI), και πειράζουμε μια μεταβλητή τη φορά. Αν το κόστος, μειωθεί ποσοστιαία περισσότερο απο την ταχύτητα, τότε η επιλογή μας δικαιώνει, και την κρατάμε, ειδάλλως, δεν την υιοθετούμε.

Η συνάρτηση κόστους που επιλέχθηκε για την άσκηση περιγράφεται παρακάτω :

### Eval = (L1data_size*L1data_cost*sqrt(L1data_assoc)*log(cacheline_size) + L1instruction_size*L1instruction_cost*sqrt(L1instruction_assoc)*log(cacheline_size) +L2_size*L2_cost*sqrt(L2_assoc)*log(cacheline_size)) * CPI

* **L1_cost** είναι μια τάξη μεγέθους μεγαλύτερο απο το L2_cost, με τιμές 10 και 1 αντίστοιχα.
* Τα **size** είναι υπολογισμένα σε kB.
* Το **assoc**, υπολογίζεται επι την τετραγωνική ρίζα του, καθώς δεν αυξάνει εκθετικά την πολυπλοκότητα του συστήματος.
* Ομόιως και το **cacheline size**, το οποίο όπως αναφέρθηκε και σε διάλεξη φέτος, αυξάνει την πολυπλοκότητα, απαιτώντας παραπάνω πύλες και συνδέσεις με L2cache και RAM.
* Το **CPI** , πολλαπλασιάζεται στο τέλος, καθώς θέλουμε να είναι αντιστρόφος ανάλογο του κόστους, που αποτελεί τον πρώτο όρο της συνάρτησης Eval(συνάρτηση κόστους)


### Αποτελέσματα αναζήτησης της βέλτιστης υλποίησης.

Benchmarks | L1 Data size kB | L1 Data Assoc | L1 Instruction Size kB | L1 Istruction Assoc| L2 Size kB | L2 Assoc | Cacheline Size | CPI | Cost

--- | --- | --- | --- | --- | --- | ---| --- | ---
401.bzip2 | 128 | 2 | 16 | 2 | 4096 | 16 | 256 | 1.563040 | 159656.34 |
401.bzip2 (PPC) | 64 | 2 | 16 | 2 |	1024 |  2 | 64 | 1.634346 | 17533.17 |
429.mcf | 64 | 4 | 64 | 2 |	4096 |  8 | 512 | 1.064488 | 33743.69 |
429.mcf (PPC) | 16 | 2 | 32 | 2 |	1024 | 2 | 32 | 1.126211 | 8301.91 |
456.hmmer | 128 | 8 | 128 | 8 |	1024 |  2 | 512 | 1.177334 | 63816.62 |
456.hmmer (PPC) | 32 | 2 | 16 | 2 |	1024 |  2 | 32 | 1.195885 | 8815.51 |
458.sjeng | 128 | 4 | 128 | 2 |	4096 | 8 | 2048 | 2.636396 | 320728.33 |
458.sjeng (PPC) | 16 | 2 | 16 | 2 | 1024 |  2 | 512 | 3.071029 | 123 |
470.lbm | 16 | 2 | 16 | 2 |	4096 |  4 | 2048 | 1.374752 | 90611.81 |
470.lbm (PPC) | 16 | 2 | 16 | 2 |	1024 |  2 | 512 | 1.492126 | 36413.81 |




## Βιβλιογραφία  

https://cs.stackexchange.com/questions/32149/what-are-system-clock-and-cpu-clock-and-what-are-their-functions
  
  








