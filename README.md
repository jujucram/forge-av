# ForgeAV

Antivirus léger pour Windows.

## À propos
ForgeAV propose un scanner de fichiers, un scan de processus, une surveillance en temps réel et un mode multithread pour des analyses rapides.

## Fonctionnalités
- Scan de dossier
- Scan des processus en cours
- Surveillance en temps réel
- Scan rapide multithread
- Quarantaine des fichiers suspects
- Logs de scan

## Installation
### Prérequis
- `gcc` (MinGW ou autre compilateur compatible)
- Windows
- Exécution recommandée en administrateur

### Compilation
- Utilisez `build.bat` dans le dossier racine
- Ou exécutez manuellement :
  `gcc main.c core/*.c security/*.c -o forgeav.exe -lcrypt32`

## Utilisation
Lancez `forgeav.exe`.

Menu disponible :
1. Scanner un dossier
2. Scanner les processus
3. Surveillance temps réel
4. Scan rapide multi-thread

> Démarrez en mode administrateur pour autoriser l’accès aux dossiers sensibles.

## Structure du projet
- `main.c` - point d’entrée
- `core/` - logique principale du scanner
- `security/` - gestion des logs et quarantaine
- `database/` - signatures et listes de hachages
- `assets/` - logo et captures d’écran

## Assets
- `assets/logo/logo.png` - logo du projet
- `assets/screenshots/` - captures d’écran

## Tests
- Créez un fichier contenant le mot `trojan` pour tester la détection.

## Quarantaine et logs
- `logs/` - fichiers de journalisation des scans
- `quarantine/` - fichiers isolés