[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/push_swap/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/push_swap/blob/master/README.fr.md)

*Langage de programmation C* • *Pensée algorithmique* • *Analyse de complexité* • *Listes doublement chaînées circulaires* • *Gestion des erreurs* • *Gestion de la mémoire* • *Conformité aux normes* • *Automatisation de la compilation avec Makefile*

# Push Swap

Trier des données sur une pile en utilisant un ensemble limité d'instructions, avec le moins d'actions possibles. Cela implique de manipuler divers algorithmes et de choisir la solution la plus appropriée pour un tri optimisé des données.

| Clé | Valeur |
| --- | --- |
| **Nom du programme** | `push_swap` |
| **Fichiers à rendre** | Makefile, *.h, *.c |
| **Arguments** | Pile `a` sous forme de liste d'entiers (le premier argument doit être au sommet de la pile). |
| **Fonctions externes autorisées** | `read`, `write`, `malloc`, `free`, `exit` |
| **Variables globales autorisées** | Aucune |

- Deux piles, `a` et `b`, sont utilisées.
- Au départ :
	- La pile `a` contient un nombre aléatoire de nombres négatifs et/ou positifs sans doublons.
	- La pile `b` est vide.
- L'objectif est de trier les nombres dans l'ordre croissant dans la pile `a` en utilisant les opérations suivantes :
	- `sa` (swap a) : Échange les 2 premiers éléments au sommet de la pile `a`. Ne rien faire s'il n'y a qu'un seul élément ou aucun.
	- `sb` (swap b) : Échange les 2 premiers éléments au sommet de la pile `b`. Ne rien faire s'il n'y a qu'un seul élément ou aucun.
	- `ss` : Exécute `sa` et `sb` en même temps.
	- `pa` (push a) : Prend le premier élément au sommet de `b` et le met au sommet de `a`. Ne rien faire si `b` est vide.
	- `pb` (push b) : Prend le premier élément au sommet de `a` et le met au sommet de `b`. Ne rien faire si `a` est vide.
	- `ra` (rotate a) : Décale tous les éléments de la pile `a` d'une position vers le haut. Le premier élément devient le dernier.
	- `rb` (rotate b) : Décale tous les éléments de la pile `b` d'une position vers le haut. Le premier élément devient le dernier.
	- `rr` : Exécute `ra` et `rb` en même temps.
	- `rra` (reverse rotate a) : Décale tous les éléments de la pile `a` d'une position vers le bas. Le dernier élément devient le premier.
	- `rrb` (reverse rotate b) : Décale tous les éléments de la pile `b` d'une position vers le bas. Le dernier élément devient le premier.
	- `rrr` : Exécute `rra` et `rrb` en même temps.

- Le programme affiche la liste la plus petite possible d'instructions pour trier la pile `a`, avec le plus petit nombre en haut.

## Utilisation

```shell
git clone git@github.com:nfauconn/push_swap.git
cd push_swap/Projet
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
8
>
```

- Pour vérifier si la liste a été correctement triée :
```shell
> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
>
```