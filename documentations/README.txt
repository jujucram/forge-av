============================================================
                     FORGEAV DOCUMENTATION
============================================================


SYSTEM OVERVIEW

ForgeAV est un antivirus en ligne de commande développé en langage C.
Il est conçu pour analyser des fichiers et détecter des menaces en
utilisant un moteur basé sur des signatures et des modules de sécurité.

Le projet est structuré de manière modulaire avec une séparation claire
entre le cœur du moteur (core) et les composants de sécurité (security).

ForgeAV utilise également des fonctionnalités cryptographiques du système
Windows via la bibliothèque crypt32 pour renforcer certaines opérations.


------------------------------------------------------------
CORE FEATURES
------------------------------------------------------------

- Analyse de fichiers en temps réel via la console
- Détection de signatures malveillantes
- Architecture modulaire (core / security)
- Intégration de fonctions de sécurité système
- Support des API cryptographiques Windows
- Code structuré pour évolution future


------------------------------------------------------------
PROJECT STRUCTURE
------------------------------------------------------------

ForgeAV/
|
|-- main.c
|
|-- core/
|   |-- scanner.c
|   |-- file_utils.c
|   |-- engine.c
|
|-- security/
|   |-- crypto.c
|   |-- hash.c
|   |-- integrity.c
|
|-- signatures/
|   |-- database.txt
|
|-- build/
|
|-- README.txt


Description des modules :

main.c
Point d’entrée du programme. Gère l’interaction utilisateur.

core/
Contient le moteur principal d’analyse :
- lecture des fichiers
- logique de scan
- gestion des résultats

security/
Contient les fonctions de sécurité avancées :
- hashing
- vérification d’intégrité
- opérations cryptographiques

signatures/
Base de données des signatures malveillantes


------------------------------------------------------------
COMPILATION
------------------------------------------------------------

Commande officielle :

gcc main.c core/*.c security/*.c -o forgeav.exe -lcrypt32

Explication :

main.c
Fichier principal

core/*.c
Modules du moteur de scan

security/*.c
Modules de sécurité

-lcrypt32
Bibliothèque Windows pour les fonctions cryptographiques


------------------------------------------------------------
EXECUTION
------------------------------------------------------------

Lancer le programme :

forgeav.exe


------------------------------------------------------------
USAGE FLOW
------------------------------------------------------------

1. L’utilisateur lance ForgeAV
2. Le programme demande un chemin de fichier
3. Le moteur charge les signatures
4. Le fichier est analysé
5. Les résultats sont affichés


Exemple :

Enter file path: sample.exe

[INFO] Initializing engine...
[INFO] Loading signatures...
[INFO] Scanning file...

[ALERT] Threat detected: Trojan.Generic


------------------------------------------------------------
SCAN ENGINE LOGIC
------------------------------------------------------------

Le moteur de ForgeAV fonctionne selon les étapes suivantes :

- Ouverture du fichier cible
- Lecture binaire ou texte
- Chargement de la base de signatures
- Comparaison avec les signatures
- Vérification d’intégrité (optionnelle)
- Retour des résultats


------------------------------------------------------------
SECURITY MODULE
------------------------------------------------------------

Le module security implémente :

- Fonctions de hash (MD5, SHA)
- Vérification d’intégrité des fichiers
- Utilisation de crypt32 pour certaines opérations système

Ce module permet d’ajouter des mécanismes avancés de détection.


------------------------------------------------------------
SIGNATURE DATABASE
------------------------------------------------------------

Localisation :

signatures/database.txt

Format :

Chaque ligne correspond à une signature.

Exemple :

trojan_generic
malware_test
virus_sample


------------------------------------------------------------
LIMITATIONS
------------------------------------------------------------

- Pas de protection en temps réel
- Pas d’analyse heuristique avancée
- Détection limitée aux signatures
- Interface uniquement en ligne de commande


------------------------------------------------------------
FUTURE IMPROVEMENTS
------------------------------------------------------------

- Analyse heuristique
- Scan de répertoires complets
- Interface graphique
- Base de signatures dynamique
- Détection comportementale
- Multi-threading


------------------------------------------------------------
SECURITY NOTICE
------------------------------------------------------------

ForgeAV est un projet éducatif.

Il ne doit pas être utilisé comme solution de sécurité principale
dans un environnement de production.


------------------------------------------------------------
AUTHOR
------------------------------------------------------------

Brandon Moukam
Étudiant en informatique
GitHub : https://github.com/jujucram


------------------------------------------------------------
LICENSE
------------------------------------------------------------

MIT License


============================================================
                     END OF DOCUMENT
============================================================
