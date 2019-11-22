# Architecture_lab1

## Πρώτο εργαστήριο

Σε αυτο το εργαστήριο, κάναμε μια **εισαγωγή στο gem5**, τρέξαμε κάποια μικρά benchmarks, περιάξαμε λίγο τις προδιαγραφές και παρατηρίσαμε διαφορές στα τελικά στατιστικά. 

Στο αρχείο **starter_se.py** ορίζονται τα **βασικά χαρακτηριστικά** του συστήματος, τα οποία παρουσιάζονται στον παρακάτω **πίνακα** :

| Χαρακτηριστικά | Τιμές |
|   --- | ---|              
| Τύπος CPU | MinorCPU |
| Συχνότητα λειτουργίας CPU | 4GHz |
| Αριθμός πυρήνων επεξεργαστή | 1 |
| Τύπος μνήμης | DDR3 |
| Συχνότητα λειτουργίας μνήμης | 1600ΜΗz |
| Μέγεθος μνήμης | 2GB |
| Κανάλια μνήμης | 2 |
| Μέγεθος cache line | 64 bytes |
| Βολτ του συστήματος | 3.3V |
| Συχνότητα λειτουργίας Συστήματος | 1GHz |  

 
> **Τρέχουμε τη προσομοίωση στο gem5 με τις παραπάνω προδιαγραφές**  


Ξεκινόντας, τρέχουμε το precompiled αρχείο **hello**, που υλοποιεί ένα απλό πρόγραμμα, το οποίο τυπώνει _"Hello world"_ στο terminal. Ως **configuration** αρχείο χρησιμοποιούμε το **starter_se.py** , με τις _default_ τιμές που ορίζει, εκτός απο το **cpu model** το οποίο ορίσαμε εμείς ως **"minor"**.  


<h><p align='center'>
  <b>CPU type</b>
</p></h>

![cputype](https://github.com/nikifori/Architecture_lab1/blob/master/Screenshot%20from%202019-11-19%2014-37-49.png)


<h><p align='center'>
  <b>Number of CPU's , CPU Frequency </b>
</p></h>

> #### Στο cpu cluster, έχει μόνο έναν cpu, με cpuid = 0.

![cpyfreq](https://github.com/nikifori/Architecture_lab1/blob/master/Screenshot%20from%202019-11-19%2014-37-25.png)


<h><p align='center'>
  <b>Memory and Cache line size</b>
</p></h>

![memory](https://github.com/nikifori/Architecture_lab1/blob/master/Screenshot%20from%202019-11-19%2015-12-25.png)


<h><p align='center'>
  <b>Global Frequency</b>
</p></h>

![GlobalFrequency](https://github.com/nikifori/Architecture_lab1/blob/master/Screenshot%20from%202019-11-19%2014-33-33.png)


<h><p align='center'>
  <b>System's Volts</b>
</p></h>

![Volts](https://github.com/nikifori/Architecture_lab1/blob/master/Screenshot%20from%202019-11-19%2014-34-54.png)


<p align='center'><h2>
  <b>In-Order-CPU models στον GEM5</b>
</h2></p>

Στον **gem5**, μας δίνεται η δυνατότητα επιλογής μοντέλων **in-order-CPUs**, οι οποίες περιγράφονται αναλυτικά απο κάτω:

- ### AtomicSimpleCPU
    Χρησιμοποιεί **Atomic memory access**. Στον gem5, τρέχει όλες τις διεργασίες **για μια εντολή σε κάθε tick**, έτσι μπορεί να παρέχει μια σχετική εκτίμηση του χρόνου πρόσβασης στην μνήμη cache, χρησιμοποιόντας τις εκτημήσεις καθυστέρισης των atomic accesses. Συνήθως, το AtomicSimpleCPU παρέχει τη **γρηγορότερη προσομοίωση**, και χρησιμοποιείται έτσι ώστε να φτάσουμε γρήγορα σε **_περιοχές ενδιαφέροντος_** (Region Of Interest) στο gem5.

- ### TimingSimpleCPU
     Αντί για atomic, χρησιμοποιεί **timing memory access**. Αυτό σημαίνει ότι περιμένει να επιστρέψει το αποτέλεσμα της μνήμης, πριν προχωρήσει παρακάτω. Ο παραπάνω τρόπος πρόσβασης στη μνήμη, είναι **πιο ρεαλιστικός** απο τον atomic, και δίνει πιο πραγματικά αποτελέσματα όσο αναφορά τους **χρόνους προσομοίωσης**. Το TimingSimple, αποτελέι ένα γρήγορο για προσομοίωση μοντέλο, καθώς **απλοποιεί κάποιες έννοιες** όπως το **pipelining**, δηλαδή τρέχει μία εντολή σε κάθε χρονικό διάστημα. Κάθε αριθμιτική πράξη εκτελείται σε 1 κύκλο ρολογιού, ενώ η πρόσβαση στη μνήμη παίρνει παραπάνω απο 1.
     
- ### MinorCPU
     Το MinorCPU, είναι ένα ευέλικτο in-orderCPU μοντέλο, το οποίο είναι **πιο αναλυτικό** και περιεκτικό μοντέλο, το οποίο χρησιμοποιούμε για να **προσομοιώσουμε πραγματικά συστήματα**. Έχει **pipeline 4 σταδίων**, **παραμετροποιήσημες δομές δεδομένων και εκτελέσιμη συμπεριφορά**. Επομένως, μπορεί να παραμετροποιηθεί σε επίπεδο μικροαρχιτεκτονικής, έτσι ώστε να **προσομοιώνει έναν συγκεκριμένο επεξεργαστή**.
     
- ### HPI (High-Performance In-order CPU)
     Χρησιμοποιεί ως **βάση του το MinorCPU** και είναι βασιμένο στην **ARM αρχιτεκτονική**. Το HPI CPU μοντέλο, είναι ρυθμισμένο, έτσι ώστε να αποτελέι την αναπαράσταση ενός **μοντέρνου in-order Armv8-A**. Έχει το ίδιο **4 σταδίων pipeline** με το MinorCPU. Διαθέτει **Interrupt Controller**, το οποίο επιτρέπει στο software, να δημιουργεί, να σβήνει και να ιεραρχεί(σε επίπεδο hardware) interrupts απο συγκεκριμένες πηγές, αλλά και να δημιουρεί interupts στο software. Επιπρόσθετα, έχει **Floating-Point και Data Processing Units**, τα οποία μπορούν να μοντελοποιηθούν απο στο στάδιο της εκτέλεσης του pipeline στο MinorCPU. Διαθέει **διαφορετικά instruction και data buses**, δηλαδή έχει instruction cache(ICache) και data cache (DCache). Άρα έχει ξεχωριστά instruction και data L1 buses, και κοινή L2 Cache. Τέλος, στο **Memory Management Unit**, μια πολύ σημαντική λειτουργία, είναι η δυνατότητα που δίνει στο σύστημα, να **τρέχει πολλαπλά ανεξάρτητα προγράμματα, στη δικιά τους virtual memory**, χωρίς να χρειάζεται να ξέρουν την πραγματική τους φυσική θέση στο hardware.
     
<p align='center'><h2>
  <b>Αποτελέσματα και Συμπεράσματα απο το δικό μας πρόγραμμα</b>
</h2></p>

Όλα τα benchmarks, τρέξανε για το ίδιο [πρόγραμμα](https://github.com/nikifori/Architecture_lab1/blob/master/Test_for.c), γραμμένο σε γλώσσα C

- ### MinorCPU vs TimingSimpleCPU
     Συμφωνα με τα στατιστικά αρχεία που προέκυψαν, για το [MinorCPU](https://github.com/nikifori/Architecture_lab1/blob/master/Minor.txt) και [TimingSimpleCPU](https://github.com/nikifori/Architecture_lab1/blob/master/TimingSimple.txt), προκύπτουν τα παρακάτω συμπεράσματα.
     - Το μοντέλο του **MinorCPU**, περατώνει το προς προσομοίωση **πρόγραμμα πιο γρήγορα**, κάτι που είναι λογικό, καθώς διαθέτει 4 σταδίων pipeline, το οποίο, λέιπει απο το TimingSimple.
     - Ο **Gem5**, τρέχει πιο γρήορα στο **TimingSimple**, καθώς είναι πιο **απλό μοντέλο**, απο το Minor.
     
     
- ### MinorCPU 2GHz vs MinorCPU 4GHz
     Συμφωνα με τα αρχεία [MinorCPU 2GHz](https://github.com/nikifori/Architecture_lab1/blob/master/Minor.txt) και [MinorCPU 4GHz](https://github.com/nikifori/Architecture_lab1/blob/master/Minor_4GHz.txt), προκύπει ότι :
     - Το μοντέλο με τα **4GHz** τρέχει το πρόγραμμα σαφώς πιο **γρήγορα**
     - Ο **Gem5** τρέχει την προσομοίωση σχεδόν στον **ίδιο χρόνο**, αφού πρόκειται για το ίδιο μοντέλο CPU, με την **ελάχιστη διαφορά** που παρατηρείται, να οφείλεται στη **διαφορά χρόνου ολοκλήρωσης** του μοντέλου **των 2ghz με αυτό των 4ghz** για το προς προσομοίωση πρόγραμμα.
     
- ### MinorCPU DDR3 vs MinorCPU DDR4
     Σύμφωνα με τα αρχεία [MinorCPU DDR3](https://github.com/nikifori/Architecture_lab1/blob/master/Minor.txt) και [MinorCPU DDR4](https://github.com/nikifori/Architecture_lab1/blob/master/Minor_DDR4.txt) προκύπτει ότι :
     - **Δεν παρατηρείται**, καμία σημαντική **διαφορά** στους χρόνους προσομοίωσης προγράμματος και συστήματος, αφού οι συχνότητες του συστήματος παραμένουν ίδεις. Η ελάχιστη διαφορά υπερ της DDR3 οφείλεται στο γεγονός πως έχει μικρότερο latency απο την DDR4, αλλά σε τιμές που δεν μας δίνουν σηματνική διαφορά.
     
     
     
     
     
     
     
     
     
