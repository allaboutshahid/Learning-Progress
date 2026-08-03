#include<stdio.h>

int main()
{
    int a[50], size, i;
    int ch, ch1, ch2;
    int pos, num;

    printf("Enter size of array: ");
    scanf("%d",&size);

    printf("Enter array elements:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }

    while(1)
    {
        printf("\n\n===== MAIN MENU =====");
        printf("\n1. Traverse");
        printf("\n2. Insert");
        printf("\n3. Delete");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nArray Elements are:\n");
                for(i=0;i<size;i++)
                {
                    printf("%d ",a[i]);
                }
                printf("\n");
                break;

            case 2:

                while(1)
                {
                    printf("\n\n--- INSERT MENU ---");
                    printf("\n1. Insert at Specific Position");
                    printf("\n2. Insert at Beginning");
                    printf("\n3. Insert at End");
                    printf("\n4. Back");

                    printf("\nEnter your choice: ");
                    scanf("%d",&ch1);

                    switch(ch1)
                    {
                        case 1:
                            printf("Enter Position: ");
                            scanf("%d",&pos);

                            if(pos<1 || pos>size+1)
                            {
                                printf("Invalid Position\n");
                                break;
                            }

                            printf("Enter Number: ");
                            scanf("%d",&num);

                            for(i=size-1;i>=pos-1;i--)
                            {
                                a[i+1]=a[i];
                            }

                            a[pos-1]=num;
                            size++;

                            printf("Insertion Successful.\n");
                            break;

                        case 2:

                            printf("Enter Number: ");
                            scanf("%d",&num);

                            for(i=size-1;i>=0;i--)
                            {
                                a[i+1]=a[i];
                            }

                            a[0]=num;
                            size++;

                            printf("Insertion Successful.\n");
                            break;

                        case 3:

                            printf("Enter Number: ");
                            scanf("%d",&num);

                            a[size]=num;
                            size++;

                            printf("Insertion Successful.\n");
                            break;

                        case 4:
                            goto mainmenu;

                        default:
                            printf("Invalid Choice\n");
                    }
                }

            case 3:

                while(1)
                {
                    printf("\n\n--- DELETE MENU ---");
                    printf("\n1. Delete at Specific Position");
                    printf("\n2. Delete at Beginning");
                    printf("\n3. Delete at End");
                    printf("\n4. Back");

                    printf("\nEnter your choice: ");
                    scanf("%d",&ch2);

                    switch(ch2)
                    {
                        case 1:

                            printf("Enter Position: ");
                            scanf("%d",&pos);

                            if(pos<1 || pos>size)
                            {
                                printf("Invalid Position\n");
                                break;
                            }

                            for(i=pos-1;i<size-1;i++)
                            {
                                a[i]=a[i+1];
                            }

                            size--;

                            printf("Deletion Successful.\n");
                            break;

                        case 2:

                            for(i=0;i<size-1;i++)
                            {
                                a[i]=a[i+1];
                            }

                            size--;

                            printf("Deletion Successful.\n");
                            break;

                        case 3:

                            if(size>0)
                            {
                                size--;
                                printf("Deletion Successful.\n");
                            }
                            else
                            {
                                printf("Array is Empty.\n");
                            }

                            break;

                        case 4:
                            goto mainmenu;

                        default:
                            printf("Invalid Choice\n");
                    }
                }

            case 4:

                printf("Program Exited Successfully.\n");
                return 0;

            default:

                printf("Invalid Choice\n");
        }

mainmenu:
        ;
    }

    return 0;
}