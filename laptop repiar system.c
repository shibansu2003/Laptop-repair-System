
#include <stdio.h>
#include <string.h>
#define MAX_CLIENTS 100
#define MAX_LAPTOPS 100
struct client
{
    int id;
    char name[50];
    char address[100];
};
struct laptop
{
    int id;
    char model[50];
    char brand[50];
};
struct expert
{
    int id;
    char name[50];
    char expertise[50];
};
struct client clients[MAX_CLIENTS];
int num_clients=0;
struct laptop laptops[MAX_LAPTOPS];
int num_laptops=0;
struct expert experts[MAX_CLIENTS];
int num_experts=0;
void add_clients()
{
    if (num_clients>=MAX_CLIENTS)
    {
        printf("Error:maximum number of clients reached.\n");
        return;
    }
    struct client c;
    printf("Enter Client ID: ");
    scanf("%d",&c.id);
    printf("Enter Client Name: ");
    scanf("%s",c.name);
    printf("Enter Client Address: ");
    scanf("%s",c.address);
    clients[num_clients++]=c;
    printf("Clients Added Successfully.\n");

}
void add_laptop()
{
    if (num_laptops>=MAX_LAPTOPS)
    {
        printf("Error: Maximum number of laptop reached.\n");
        return;
    }
    struct laptop l;
    printf("Enter Laptop ID: ");
    scanf("%d",l.id);
    printf("Enter Laptop Brand: ");
    scanf("%s",l.brand);
    printf("Enter Laptop Model: ");
    scanf("%s",l.model);

    laptops[num_laptops++]=l;
    printf("Laptops Added Successfully.\n");

}
void update_client()
{
    int id;
    printf("Enter Client ID to update: ");
    scanf("%d",&id);
    int i;
    for (i=0; i <num_clients; i++)
    {
        if (clients[i].id==id)
        {
            struct client c;
            printf("Enter new client name; ");
            scanf("%s",c.name);
            printf("Enter new Clients address: ");
            scanf("%s",c.address);
            clients[i]=c;
            printf("Client Updated successfully.\n");
            return;

        }
    }
    printf("ERROR: Client not found.\n");
}

void update_laptop()
{
    int id;
    printf("Enter laptop ID to update:");
    scanf("%d",&id);
    int i;
    for (i=0; i<num_laptops; i++)
    {
        if (laptops[i].id==id)
        {
            struct laptop l;
            printf("Enter new laptop brand: ");
            scanf("%s",l.brand);
            printf("Enter new laptop model: ");
            scanf("%s",l.model);

            laptops[i]=l;
            printf("Laptop Updated Successfully.\n");
            return;
        }
    }
    printf("ERROR: Laptop not found.\n");
}


void delete_client()
{
    int id;
    printf("Enter Client ID to delete: ");
    scanf ("%d",&id);
    int i;
    for (i=0; i<num_clients; i++)
    {
        if (clients[i].id==id)
        {
            memmove(&clients[i],&clients[i+1],(num_clients-i-1)*sizeof(struct client));
            num_clients--;
            printf("Client deleted succesfully.\n");
            return;
        }
    }
}
void delete_laptop()
{
    int id;
    printf("Enter laptop ID To delete: ");
    scanf("%d",&id);
    int i;
    for (i=0; i<num_laptops; i++)
    {
        if (laptops[i].id==id)
        {
            memmove(&laptops[i],&laptops[i+1],(num_laptops-i-1)*sizeof(struct laptop));
            num_laptops--;
            printf("Laptop deleted Successfully.\n");
            return;
        }
    }
    printf("ERROR: Laptop not found.\n");
}

void add_expert()
{
    struct expert e ;
    printf("Enter Expert ID: ");
    scanf("%d",&e.id);
    printf("Enter Expert Name: ");
    scanf("%s",e.name);
    printf("Enter Expert Expertise: ");
    scanf("%s",e.expertise);
    experts[num_experts++]=e;
    printf("Enter added Successfully.\n");
}
void print_menu()
{
    printf("\n");
    printf("1.Add Client\n");
    printf("2.Add Laptop\n");
    printf("3.Update Client\n");
    printf("4.Update Laptop\n");
    printf("5.Delete Client\n");
    printf("6.Delete Laptop\n");
    printf("7.Add Expert\n");
    printf("Exit\n");

}
void print_clients()
{
    printf("ID\tname\taddress\n");
    int i;
    for (i=0; i<num_clients; i++)
    {
        printf("%d\t%s\t%s\n",clients[i].id,clients[i].name,clients[i].address);
    }
}
void print_laptops()
{
    printf("ID\tBrand\tModel\n");
    int i;
    for (i=0; i<num_laptops; i++)
    {
        printf("%d\t%s\t%s\n",laptops[i].id,laptops[i].brand,laptops[i].model);
    }
}
void print_experts()
{
    printf("ID\tName\tExpertise\n");
    int i;
    for (i=0; i<num_experts; i++)
    {
        printf("%d\t%s\t%s\n",experts[i].id,experts[i].name,experts[i].expertise);
    }
}
int main()
{
    int choice;
    do
    {
        print_menu();
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            add_clients();
            break;
        case 2:
            add_laptop();
            break;
        case 3:
            update_client();
            break;
        case 4:
            update_laptop();
            break;
        case 5:
            delete_client();
            break;
        case 6:
            delete_laptop();
            break;
        case 7:
            add_expert();
            break;
        case 8:
            printf("GoodBye!\n");
            break;
        default:
            printf("Invalid Choice.Please Try Again.\n");
        }
        printf("\n");
        printf("Clients:\n");
        print_clients();
        printf("\n");
        printf("Laptops:\n");
        print_laptops();
        printf("\n");
        printf("Experts:\n");
        print_experts();
        printf("\n");


    }
    while (choice!=8);
    return 0;
}
