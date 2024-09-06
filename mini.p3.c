#include <stdio.h>
#include <string.h>


#define max 100
struct	contact
{
	char name[max];
	char phone[max];
	char email[max];
};
int 	total_contacts = 0;
struct contact contacts[max];

void add_contact()
{
	char name[max];
       	if (total_contacts >= max)
       	{
	  printf("Contact list is full!\n");
		 return;
	}
	
	  
	 printf("Enter name: ");     
	 scanf(" %[^\n]", name);

	 for (int i = 0; i < total_contacts; i++)
	 {         
		 if (strcmp(contacts[i].name, name) == 0) 
		 {            
			 printf("This contact already exists.\n");
			 return;   
		 }
	 }


	 strcpy(contacts[total_contacts].name, name);
	 printf("Enter phone number:"); 
	 scanf("%s", contacts[total_contacts].phone);
	 printf("Enter email address: ");
	 scanf("%s", contacts[total_contacts].email);




	 total_contacts++;
	printf("Contact added successfully!\n");
}
void show_contact() 
{
	if (total_contacts == 0)  
	{
		printf("No contacts available!\n"); 
		return;    
	}
	for (int i = 0; i < total_contacts; i++)
	{         
		printf("Name: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);     
	} 
}
void edit_contact() 
{     
	char name[max];     
	printf("Enter the name of the contact to edit: ");    
	scanf(" %[^\n]", name);    
	for (int i = 0; i < total_contacts; i++) 
	{         
		if (strcmp(contacts[i].name, name) == 0)
		{    
			printf("Enter new phone number: ");    
			scanf("%s", contacts[i].phone);
			printf("Enter new email address: ");   
			scanf("%s", contacts[i].email); 
			printf("Contact updated successfully!\n");   
			return;        
		} 
	}  
	printf("Contact not found!\n"); 
}
void delete_contact()
{ 
	char name[max];
	printf("Enter the name of the contact to delete: ");  
	scanf(" %[^\n]", name);
	for (int i = 0; i < total_contacts; i++) 
	{      
		if (strcmp(contacts[i].name, name) == 0)
		{        
			for (int j = i; j < total_contacts - 1; j++)
			{                
				contacts[j] = contacts[j + 1];   
			}             
			total_contacts--;   
			printf("Contact deleted successfully!\n");  
			return;     
		}   
	}   
	printf("Contact not found!\n");
}

void search_contact()
{
	char name[50];  
	printf("Enter the name to search: ");    
	scanf(" %[^\n]", name);
	for (int i = 0; i < total_contacts; i++) 
	{     
		if (strcmp(contacts[i].name, name) == 0)
		{     
			printf("Name: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);        
			return;
		}
	}
	printf("Contact not found!\n"); 
}
int	main()
{
	int choice;
     while(1)
     {
	printf("Welcome to your contact, please chose one of the options below\n");
	printf("1- Add a Contact\n");
	printf("2- Edit a Contact\n"); 
	printf("3- Delete a Contact\n");
	printf("4- Show All Contacts\n");
	printf("5- Search for a Contact\n");
	printf("6 - exit .. \n");
	
	scanf("%d", &choice);
	if (choice == 6)
	{
		break;
	}
	switch (choice)
	{
		case 1:
			add_contact();
			break;
		case 2:
			edit_contact();
			break;
		case 3:
			delete_contact();
			break;
		case 4:
			show_contact();
			break;
		case 5:
			search_contact();
			break;
		default:
			 printf("Invalid choice. Please enter a number between 1 and 6.\n");
			 break;
      
	}

        }
}
