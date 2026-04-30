
ForgeAV Antivirus 

- Compilation:
gcc main.c core/*.c security/*.c -o forgeav.exe -lcrypt32

- Utilisation:
Lancer: forgeav.exe

Options:
1- Scanner un dossier
2- Scanner les processus
3- Surveillance temps réel
4- Scan rapide multi-thread

- Test:
Créer un fichier contenant "trojan" → Il sera détecté

- Dossiers:
logs/ → logs des scans
quarantine/ → fichiers isolés

 Important:
- Lancer en admin pour scanner certains dossiers
- Ne pas scanner C:\ complet au début (lent)

Projet antivirus by Brandon.