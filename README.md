# Ordonnanceur/Scheduler

## Auteurs

- [Adam Boislevant Fleury](https://github.com/AdamBoislevant)

- [Amandine Chantome](https://github.com/amandine-ch)

## Description

Ce programme permet d'entrer des informations sur des processus, les ajouter à une file, puis de tous les exécuter à la suite en fonction de leur temps d'exécution. 
L'utilisateur peut ajouter autant de processus qu'il le souhaite, ils seront tous exécuter par la suite.

L'ordonnanceur choisi n'a pas de gestion de priorité, les processus sont exécutés dans l'ordre dans lequel ils ont étés ajoutés.

This program allows you to enter informations on processes, add them to a queue, then execute them all depending of their execute time.
The user can add as much process as he wants, they will all be executed afterwards.

The chosen scheduler doesn't have a priority management, the processes are executed in the order they have been added.

## Run le projet localement

Cloner le projet 
// clone the project

se rendre dans le dossier du projet
// go to the root directory

vider les dossier obj et bin
// clean the obj and bin folders

```bash
  make clean
```

compiler le projet
// compile the project

```bash
  make
```
éxécution du projet
// run the project

```bash
  bin/main
```

suivre les instructions données par le programme.
// follow the instruction given by the program.
