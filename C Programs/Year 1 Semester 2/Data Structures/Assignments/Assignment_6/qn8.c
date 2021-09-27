#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED,DELETED};

typedef struct _slot{
    int key;
    enum Marker indicator;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashDelete(int key, HashSlot hashTable[]);


int hash1(int key);
int hash2(int key);

int main()
{
    int opt;
    int i;
    int key;
    int comparison;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].indicator = EMPTY;
        hashTable[i].key = 0;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Delete a key from the hash table|\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");
    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
        case 1:
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            comparison = HashInsert(key,hashTable);
            if(comparison <0)
                printf("Duplicate key\n");
            else if(comparison < TABLESIZE)
                printf("Insert: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Key Comparisons: %d. Table is full.\n",comparison);
            break;
        case 2:
            printf("Enter a key to be deleted:\n");
            scanf("%d",&key);
            comparison = HashDelete(key,hashTable);
            if(comparison <0)
                printf("%d does not exist.\n", key);
            else if(comparison <= TABLESIZE)
                printf("Delete: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Error\n");
            break;
        case 3:
            for(i=0;i<TABLESIZE;i++) printf("%d: %d %c\n",i, hashTable[i].key,hashTable[i].indicator==DELETED?'*':' ');
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int hash1(int key)
{
    return (key % TABLESIZE);
}

int hash2(int key)
{
    return (key % PRIME) + 1;
}

int HashInsert(int key, HashSlot hashTable[])
{
    //Write your code here
    int address = hash1(key), increment = hash2(key), comparison = 0, check = 0, iterations = 0;

    /*while (check < TABLESIZE)
    {
        if (hashTable[check].key == key)
            return -1;
        check++;
    }*/

    while (hashTable[address].indicator == USED)
    {
        if (comparison > TABLESIZE) //FULL
        {
            return TABLESIZE;
        }

        comparison++;
        iterations++;

        if (hashTable[address].key == key)
            return -1;

        address = hash1(address + increment);
    }

    //address found

    check = address;

    //check other possible slots at the back
    while (hashTable[check].indicator != EMPTY && iterations < TABLESIZE)
    {
        if (hashTable[check].indicator == DELETED)
        {
            check = hash1(check + increment);
            iterations++;
            continue;
        }
        else
        {
            comparison++;
            iterations++;
            if (hashTable[check].key == key)
                return -1;
            check = hash1(check + increment);
        }
    }

    hashTable[address].key = key;
    hashTable[address].indicator = USED;
    return comparison;
}

int HashDelete(int key, HashSlot hashTable[])
{
    //Write your code here
    int address, increment, comparison = 0;
    address = hash1(key);
    increment = hash2(key);

    while (comparison < TABLESIZE)
    {
        if (hashTable[address].indicator == USED)
        {
            comparison++;
            if (hashTable[address].key == key)
            {
                hashTable[address].indicator = DELETED;
                return comparison;
            }
        }
        address = hash1(address + increment);
    }
    return -1;
}