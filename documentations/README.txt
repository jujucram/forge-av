# ForgeAV Documentation

## 1. Introduction

ForgeAV est un antivirus en ligne de commande développé en langage C.  
Ce projet a pour objectif de démontrer les bases du fonctionnement d’un antivirus, notamment la détection de menaces à partir de signatures.

Il est conçu à des fins pédagogiques pour les étudiants et développeurs souhaitant comprendre :
- l’analyse de fichiers
- la détection de malwares
- la programmation système en C

---

## 2. Fonctionnalités

- Analyse de fichiers en ligne de commande  
- Détection de signatures malveillantes  
- Affichage des résultats en temps réel  
- Code structuré et modulaire  
- Facile à compiler et à exécuter  

---

## 3. Architecture du projet

ForgeAV/
│── src/
│   ├── main.c
│   ├── scanner.c
│   ├── scanner.h
│
│── signatures/
│   └── signatures.txt
│
│── build/
│   └── forgeav.exe
│
│── README.md
│── Makefile
---

## 4. Installation

### 4.1 Clonage du projet

git clone https://github.com/jujucram/ForgeAV.git
cd ForgeAV
### 4.2 Compilation

#### Sous Windows (GCC)

gcc src/main.c src/scanner.c -o forgeav.exe
#### Sous Linux

gcc src/main.c src/scanner.c -o forgeav
---

## 5. Utilisation

### 5.1 Lancement

Sous Linux :

./forgeav
Sous Windows :

forgeav.exe
### 5.2 Analyse d’un fichier

Lors de l’exécution, le programme demande un chemin de fichier :

Enter file path: test.txt
### 5.3 Résultat

Exemple de sortie :

[INFO] Scanning file...
[ALERT] Threat detected: trojan_test
---

## 6. Fonctionnement interne

Le fonctionnement de ForgeAV repose sur une approche simple basée sur des signatures :

1. Ouverture du fichier cible  
2. Lecture du contenu  
3. Chargement des signatures depuis un fichier externe  
4. Comparaison entre le contenu et les signatures  
5. Signalement d’une menace en cas de correspondance  

---

## 7. Gestion des signatures

Les signatures sont stockées dans :

signatures/signatures.txt
Exemple de contenu :

virus123
trojan_test
malware_sample
Chaque ligne correspond à une signature recherchée dans les fichiers analysés.

---

## 8. Limitations

- Absence de protection en temps réel  
- Détection limitée aux signatures simples  
- Pas d’analyse heuristique  
- Pas de scan de répertoires  
- Pas d’interface graphique  

---

## 9. Améliorations possibles

- Ajout du scan de dossiers  
- Détection heuristique  
- Base de signatures dynamique  
- Optimisation des performances  
- Interface graphique  
- Analyse multi-thread  

---

## 10. Contribution

Les contributions sont ouvertes.

Procédure :

1. Fork du dépôt  
2. Création d’une branche  
3. Ajout des modifications  
4. Soumission d’une Pull Request  

---

## 11. Auteur

Brandon Moukam  
Étudiant en informatique  
GitHub : https://github.com/jujucram  

---

## 12. Licence

Ce projet est distribué sous licence MIT.
