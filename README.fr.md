[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/push_swap/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/push_swap/blob/master/README.fr.md)

# Projet : Push Swap

## 🏁 Objectif 🏁

Trier des données sur une pile en utilisant un ensemble limité d'instructions, avec le moins d'actions possibles. Cela implique de manipuler divers algorithmes et de choisir la solution la plus appropriée pour un tri optimisé des données.

## 🚀 Utilisation 🚀

```shell
git clone git@github.com:nfauconn/push_swap.git
cd push_swap/Project
make
```

Comment exécuter sur Bash :

- Pour vérifier les instructions :
```shell
> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
pb
ra
pb
ra
ra
rra
sb
pa
pa
>
```

- Pour vérifier le nombre d'instructions :
```shell
> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
>
```

- Pour vérifier si la liste a été correctement triée :
```shell
> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
>
```

## 💡 Compétences 💡

- **Pensée algorithmique** : Comprendre et comparer les algorithmes de tri

- **Analyse de complexité** : Analyser et prendre en compte la complexité des différentes méthodes de tri

- **Maîtrise du langage C** : Double liste chaînée circulaire, gestion de la mémoire, arithmétique des pointeurs et syntaxe générale

- **Efficacité du code** : Écrire du code efficace, chercher des moyens d'optimiser et d'améliorer la performance des algorithmes

- **Utilisation de Makefile** : Utiliser des Makefiles pour compiler, gérer les dépendances et s'assurer que la structure du projet est propre et organisée

- **Travailler avec des contraintes** : Travailler dans les limites d'un projet, en respectant les spécifications et les règles données

## 📋 Sujet 📋

Projet individuel

### Instructions Communes

1. **Langage** : Le projet doit être écrit en C.
2. **Conformité aux normes** : Le code doit adhérer à la Norme de l'école.
3. **Gestion des erreurs** : Le programme ne doivent pas se terminer de manière inattendue (par exemple, segfault, bus error, double free). De tels incidents rendront le projet non fonctionnel et entraîneront un score de 0.
4. **Gestion de la mémoire** : Toute mémoire allouée sur le tas doit être correctement libérée. Les fuites de mémoire ne sont pas tolérées.
5. **Exigences de Makefile** :
   - Doit compiler les fichiers sources pour obtenir le résultat requis avec les flags `-Wall`, `-Wextra`, et `-Werror`.
   - Ne doit pas relink.
   - Doit contenir les règles `$(NAME)`, `all`, `clean`, `fclean`, et `re`.

### Les Règles

- Deux piles, `a` et `b`, sont utilisées.
- Au début :
	- La pile `a` contient un nombre aléatoire de nombres négatifs et/ou positifs sans doublons.
	- La pile `b` est vide.
- L'objectif est de trier les nombres dans l'ordre croissant dans la pile `a` en utilisant les opérations suivantes :
	- `sa` (échanger a) : Échanger les 2 premiers éléments en haut de la pile `a`. Ne rien faire s'il y a un ou aucun élément.
	- `sb` (échanger b) : Échanger les 2 premiers éléments en haut de la pile `b`. Ne rien faire s'il y a un ou aucun élément.
	- `ss` : Effectuer `sa` et `sb` en même temps.
	- `pa` (pousser a) : Prendre le premier élément en haut de `b` et le mettre en haut de `a`. Ne rien faire si `b` est vide.
	- `pb` (pousser b) : Prendre le premier élément en haut de `a` et le mettre en haut de `b`. Ne rien faire si `a` est vide.
	- `ra` (tourner a) : Faire remonter tous les éléments de la pile `a` d'un cran. Le

premier élément devient le dernier.
	- `rb` (tourner b) : Faire remonter tous les éléments de la pile `b` d'un cran. Le premier élément devient le dernier.
	- `rr` : Effectuer `ra` et `rb` en même temps.
	- `rra` (inverser rotation a) : Faire descendre tous les éléments de la pile `a` d'un cran. Le dernier élément devient le premier.
	- `rrb` (inverser rotation b) : Faire descendre tous les éléments de la pile `b` d'un cran. Le dernier élément devient le premier.
	- `rrr` : Effectuer `rra` et `rrb` en même temps.

### Le programme

| | |
| --- | --- |
| **Nom du Programme** | `push_swap` |
| **Fichiers à Rendre** | Makefile, *.h, *.c |
| **Arguments** | Pile `a` comme une liste d'entiers (le premier argument devrait être en haut de la pile). |
| **Fonctions Externes Autorisées** | `read`, `write`, `malloc`, `free`, `exit` |
| **Libft** | Autorisé |
| **Description** | Trier les piles |

- Les variables globales sont interdites.
- Le programme doit afficher la plus petite liste d'instructions possible pour trier la pile `a`, avec le plus petit nombre en haut.
- Les instructions doivent être séparées par un `\n` et rien d'autre.
- L'objectif est de trier la pile avec le nombre le plus bas possible d'opérations.
- Si aucun paramètre n'est spécifié, le programme ne doit rien afficher.
- En cas d'erreur, afficher "Error" suivi d'un `\n` sur l'erreur standard. Les erreurs incluent : des arguments non entiers, des arguments plus grands qu'un entier, des doublons ou des instructions invalides.

```shell
> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
> ./push_swap 0 one 2 3
Error
>
```