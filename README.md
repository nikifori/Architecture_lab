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

> Στο cpu cluster, έχει μόνο έναν cpu, με cpuid = 0.

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




