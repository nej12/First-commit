//                                BAHIRDAR INSTITUE OF TECHNOLOGY
//                                    FACULTY OF COMPUTING
//                                       DEP'T OF CS

// PROJECT:ANALYSIS OF ALGORITHM(Bst assignment)
// PREPARED BY GROUP 6
// GROUP MEMBERS                                           ID
// 1.ABEL BERHANU..........................................1309026
// 2.SIMEGN ABAY...........................................1308782
// 3.YISHAK ABREHAM........................................1308824
// 4.EYOB AYALEW...........................................1311604
// 5.ESKEDAR ATINAFU.......................................1311601
// 6.BIRHANU BAYE..........................................1309117
// 7.TADELE YILAK..........................................1501515
//  DATE:Sun feb12/2023
//  SUBMITTED TO:
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
struct Star
{
  int starID;
  char name[30];
  char color[15];
  double mass;
  int temprature;
  int luminousity;
  int height;
  struct Star *left;
  struct Star *right;
};
struct Star *root = NULL;

int count = 0;
void insertstar();
void inorderTraversal(struct Star *temp);
void insertfromfile(struct Star *root);
void insertf(struct Star *temp);
void writeToFile(struct Star *root);
void preOrderTraversal(struct Star *temp);
void postOrderTraversal(struct Star *temp);
void displayMinimumNode();
void displayMaximumNode();
void searchbyname(struct Star *temp, char starname[20]);
void searchbyid(struct Star *temp, int);
void searchbycolor(struct Star *temp, char starcolor[20]);
void searchbymass(struct Star *temp, int);
void searchbytemprature(struct Star *temp, int);
void searchbyluminousity(struct Star *temp, int);
int searchforname(struct Star *temp, char name[]);
int searchforid(struct Star *temp, int);
int countnodes(struct Star *root);
void deleteminimum();
void deletemaximum();
void deleteroot();
int balanceFactor(Star *node);
Star *convertToAVL(Star *node);
void continueornot();
void exitbst();
bool isNumber(char s[]);
int main()
{
  int y;
  int maininput;
  system("cls");
  cout << "\n\n*****************************************************************WELCOME TO STARS BST(EXPLORE THE MILKY WAY)************************************************************\n\n"
       << endl;
mainmenu:
  cout << "THE NAME OF THE STAR IS THE MAIN ATTRIBUTE" << endl;
  cout << "THIS IS THE MAIN MENU. WHAT DO YOU WANT TO DO TODAY?\n\n"
       << endl;
  cout << "\t\t\t1. INSERT NEW STAR" << endl
       << endl;
  cout << "\t\t\t2. DISPLAY STAR INFORMATION." << endl
       << endl;
  cout << "\t\t\t3. SEARCH FOR A STAR" << endl
       << endl;
  cout << "\t\t\t4. COUNT THE TOTAL NUMBER OF STARS" << endl
       << endl;
  cout << "\t\t\t5. DELETE STAR" << endl
       << endl;
  cout << "\t\t\t6. DISPLAY THE STAR WITH THE MINIMUM NAME" << endl
       << endl;
  cout << "\t\t\t7. DISPLAY THE STAR WITH THE MAXIMUM NAME" << endl
       << endl;
  cout << "\t\t\t8. INSERT STAR INFORMATION FROM A FILE" << endl
       << endl;
  cout << "\t\t\t9. WRITE STAR INFORMATION TO FILE" << endl
       << endl;
  cout << "\t\t\t10. CONVERT THE STAR BST INTO AN AVL TREE." << endl
       << endl;
  cout << "\t\t\t11. EXIT." << endl;
  cin >> maininput;

  switch (maininput)
  {
  case 1:
    char b;
    system("cls");
  insert:
    insertstar();
  q:

    cout << "insert another star?(y/n):";
    cin >> b;
    if (b == 'Y' || b == 'y')
    {
      system("cls");
      goto insert;
    }
    else if (b == 'N' || b == 'n')
    {
      system("cls");
      cout << "STAR successfully inserted!" << endl;
      continueornot();
    }
    else
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto q;
      }
      else
      {
        cout << "invalid input please enter correct character." << endl;
        goto q;
      }
    }
    break;
  case 2:
    system("cls");
    int traversal;
  display:
    cout << "In what fasion do you wish to display the BST?" << endl;
    cout << "1. PREORDER traversal" << endl;
    cout << "2. INORDER traversal" << endl;
    cout << "3. POSTORDER traversal" << endl;
    cin >> traversal;
    if (traversal == 1)
    {
      char l;
      system("cls");
      preOrderTraversal(root);
    pret:
      cout << "\ndo you want to display in another fasion?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto display;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto pret;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto pret;
        }
      }
    }
    else if (traversal == 2)
    {
      char l;
      system("cls");
      inorderTraversal(root);
    inot:
      cout << "\ndo you want to display in another fasion?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto display;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto inot;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto inot;
        }
      }
    }
    else if (traversal == 3)
    {
      system("cls");
      char l;
      postOrderTraversal(root);
    postt:
      cout << "\ndo you want to display in another fasion?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto display;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto postt;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto postt;
        }
      }
    }
    else
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto display;
      }
      else
      {
        cout << "incorrect input please choose 1,2 or 3 correctly" << endl;
        goto display;
      }
    }
    break;

  case 3:
    system("cls");
    int s;
  search:
    cout << "What do you want to search the BST by?" << endl;
    cout << "1.Search by NAME" << endl;
    cout << "2.Search by ID" << endl;
    cout << "3.Search by COLOR" << endl;
    cout << "4.Search by TEMPRATURE" << endl;
    cout << "5.Search by MASS" << endl;
    cout << "6.Search by LUMINOUSITY" << endl;
    cin >> s;
    if (s == 1)
    {

      system("cls");
      char searchName[20];
      char l;
      cout << "enter the name to be searched: " << endl;
      cin.ignore();
      cin.getline(searchName, 20);
      searchbyname(root, searchName);
    searchn:
      cout << "\ncontinue search by other parameter?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto search;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto searchn;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto searchn;
        }
      }
    }
    else if (s == 2)
    {
      char l;
      system("cls");
      int searchid;
    id:
      cout << "enter the id to be searched: " << endl;
      cin >> searchid;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto id;
      }
      else
        searchbyid(root, searchid);
    searchi:
      cout << "\ncontinue search by other parameter?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto search;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto searchi;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto searchi;
        }
      }
    }
    else if (s == 3)
    {
      char l;
      system("cls");
      char searchcolor[20];
    color:
      cout << "enter the color to be searched: " << endl;
      cin.ignore();
      cin.getline(searchcolor, 20);
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto color;
      }
      else
        searchbycolor(root, searchcolor);
    searchcl:
      cout << "\ncontinue search by other parameter?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto search;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto searchcl;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto searchcl;
        }
      }
    }
    else if (s == 4)
    {
      char l;
      system("cls");
      int searchtemprature;
    temp:
      cout << "enter the temprature to be searched: " << endl;
      cin >> searchtemprature;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto temp;
      }
      else
        searchbytemprature(root, searchtemprature);
    searcht:
      cout << "\ncontinue search by other parameter?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto search;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto searcht;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto searcht;
        }
      }
    }

    // you stopped at s--5 meaning mass
    else if (s == 5)
    {
      char l;
      system("cls");
      int searchmass;
    mass:
      cout << "enter the mass to be searched: " << endl;
      cin >> searchmass;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto mass;
      }
      else
        searchbymass(root, searchmass);
    searchm:
      cout << "\ncontinue search by other parameter?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto search;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto searchm;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto searchm;
        }
      }
    }

    else if (s == 6)
    {
      char l;
      system("cls");
      int searchluminousity;
    lumin:
      cout << "enter the luminousity to be searched: " << endl;
      cin >> searchluminousity;

      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto lumin;
      }
      else
        searchbyluminousity(root, searchluminousity);
    searchc:
      cout << "\ncontinue search by other parameter?(y/n):";
      cin >> l;
      if (l == 'y' || l == 'Y')
        goto search;
      else if (l == 'n' || l == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto searchc;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto searchc;
        }
      }
    }
    else
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto search;
      }
      else
      {
        cout << "Error! Invalid Input" << endl;
        goto search;
      }
    }

    break;
  case 4:
    system("cls");
    y = countnodes(root);
    if (y == 1)
    {
      cout << "YOU HAVE " << y << " STAR IN YOUR BST" << endl;
      continueornot();
    }
    else
    {
      cout << "YOU HAVE " << y << " STARS IN YOUR BST" << endl;
      continueornot();
    }

    break;

  case 5:
    system("cls");
    int d;
  deletemenu:
    cout << "1. delete root" << endl;
    cout << "2. delete maximum" << endl;
    cout << "3. delte minimum" << endl;
    cin >> d;
    if (d == 1)
    {
      char dl;
      system("cls");
      deleteroot();
    askdelete:
      cout << "do you want to delete other parameters?(y/n)" << endl;
      cin >> dl;
      if (dl == 'y' || dl == 'Y')
        goto deletemenu;
      else if (dl == 'n' || dl == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto askdelete;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto askdelete;
        }
      }
    }
    else if (d == 2)
    {
      char dl;
      system("cls");
      cout << "Maximum Deleted Successfully" << endl;
      deletemaximum();
    askdelete1:
      cout << "do you want to delete other parameters?(y/n)" << endl;
      cin >> dl;
      if (dl == 'y' || dl == 'Y')
        goto deletemenu;
      else if (dl == 'n' || dl == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto askdelete1;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto askdelete1;
        }
      }
    }
    else if (d == 3)
    {
      char dl;
      system("cls");
      cout << "Minimum Node Deleted Successfully" << endl;
      deleteminimum();
    askdelete2:
      cout << "do you want to delete other parameters?(y/n)" << endl;
      cin >> dl;
      if (dl == 'y' || dl == 'Y')
        goto deletemenu;
      else if (dl == 'n' || dl == 'N')
        continueornot();
      else
      {
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error!invalid input" << endl;
          goto askdelete2;
        }
        else
        {
          cout << "Error! Invalid Input" << endl;
          goto askdelete2;
        }
      }
    }

    else
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << "Error!invalid input" << endl;
        goto deletemenu;
      }
      else
      {
        cout << "Error! Invalid Input" << endl;
        goto deletemenu;
      }
    }
    break;

  case 6:
    system("cls");

    cout << "YOU ARE NOW VIEWING THE MINUMUM NODE" << endl;
    displayMinimumNode();
    cout << endl;
    continueornot();

    break;
  case 7:
    system("cls");

    cout << "YOU ARE NOW VIEWING THE MAXIMUM NODE" << endl;
    displayMaximumNode();
    cout << endl;
    continueornot();

    break;
  case 8:
    system("cls");
    insertfromfile(root);
    continueornot();
    break;
  case 9:
    system("cls");
    cout << "DESTINATION FILE: newStar.txt(in append mode)" << endl;
    writeToFile(root);
    cout << endl;
    continueornot();
    break;
  case 10:
    system("cls");
    if (root == NULL)
    {
      cout << "sorry data is empty" << endl;
      continueornot();
    }
    else
    {
      convertToAVL(root);
      cout << "STAR SUCCESSFULLY CHANGED INTO AVL TREE WITH" << endl;
      cout << "BALANCE FACTOR=" << balanceFactor(root) << endl;
      cout << endl;
      continueornot();
    }
    break;
  case 11:
    exitbst();
    break;
  default:
    system("cls");
    cin.clear();
    cin.ignore();
    cout << "INVALID INPUT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    goto mainmenu;
  }

  return 0;
}

void insertstar()
{
  Star *newNode = new Star;

entn:
  cout << endl
       << "Enter NAME of star:" << endl;
  cin >> newNode->name;
  int a = searchforname(root, newNode->name);
  if (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cout << "Error!invalid input" << endl;
    goto entn;
  }
  if (a == 0)
  {
    cout << "Name already exists!" << endl;
    goto entn;
  }

enti:
  cout << endl
       << "Enter ID of star" << endl;
  cin >> newNode->starID;
  int b = searchforid(root, newNode->starID);
  if (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cout << "Error!invalid input" << endl;
    goto enti;
  }
  if (b == 0)
  {
    cout << "ID already exists!" << endl;
    goto enti;
  }
entc:
  cout << endl
       << "Enter COLOR of star" << endl;
  cin >> newNode->color;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cout << "Error!invalid input" << endl;
    goto entc;
  }
  if (isNumber(newNode->color) == true)
  {
    cin.clear();
    cin.ignore();
    cout << "Color can not be a NUMBER!" << endl;
    goto entc;
  }
entm:
  cout << endl
       << "Enter MASS of star" << endl;

  cin >> newNode->mass;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cout << "Error!invalid input" << endl;
    goto entm;
  }
entt:
  cout << endl
       << "Enter TEMPRATURE of star" << endl;
  cin >> newNode->temprature;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cout << "Error!invalid input" << endl;
    goto entt;
  }
entl:
  cout << endl
       << "Enter LUMINOUSITY of star" << endl;
  cin >> newNode->luminousity;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cout << "Error!invalid input" << endl;
    goto entl;
  }

  newNode->left = NULL;
  newNode->right = NULL;

  if (root == NULL)
    root = newNode;

  else
  {
    Star *temp = root;
    while (temp != NULL)
    {
      if (strcmp(newNode->name, temp->name) < 0)
      {
        if (temp->left != NULL)
          temp = temp->left;
        else
        {
          temp->left = newNode;
          break;
        }
      }
      else
      {

        if (temp->right != NULL)
          temp = temp->right;
        else
        {
          temp->right = newNode;
          break;
        }
      }
    }
  }
}

void inorderTraversal(struct Star *temp)
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;
  if (temp != NULL)
  {
    inorderTraversal(temp->left);
    cout << endl;
    cout << "the id of the star is: " << temp->starID << endl;
    cout << "the name of the star is: " << temp->name << endl;
    cout << "the color of the star is: " << temp->color << endl;
    cout << "the mass of the star is: " << temp->mass << endl;
    cout << "the temprature of the star is: " << temp->temprature << endl;
    cout << "the luminousity of the star is: " << temp->luminousity << endl;
    cout << endl;

    inorderTraversal(temp->right);
  }
}

void insertfromfile(Star *root)
{
  int b;
  char file[20];
  ifstream inf;
  inf.open("newStarFile.txt");
  if (inf.is_open())
  {
    for (int i = 0; i < 9; i++)
    {
      Star *newNode = new Star;
      inf >> b;
      newNode->starID = b;

      inf >> file;
      strcpy(newNode->name, file);

      inf >> strcpy(newNode->color, file);

      inf >> b;
      newNode->mass = b;

      inf >> b;
      newNode->temprature = b;

      inf >> b;
      newNode->luminousity = b;

      newNode->left = NULL;
      newNode->right = NULL;
      insertf(newNode);
    }
    cout << "\t\tStars saved into binary search tree" << endl;
    inf.close();
  }

  else
    cout << "\t\tError opening file!" << endl;
}

void insertf(struct Star *temp)
{
  Star *newNode = new Star;

  strcpy(newNode->name, temp->name);
  strcpy(newNode->color, temp->color);
  newNode->mass = temp->mass;
  newNode->starID = temp->starID;
  newNode->temprature = temp->temprature;
  newNode->luminousity = temp->luminousity;
  newNode->left = NULL;
  newNode->right = NULL;

  if (root == NULL)
    root = newNode;

  else
  {
    Star *temp = root;
    while (temp != NULL)
    {
      if (strcmp(newNode->name, temp->name) < 0)
      {
        if (temp->left != NULL)
          temp = temp->left;
        else
        {
          temp->left = newNode;
          break;
        }
      }
      else
      {

        if (temp->right != NULL)
          temp = temp->right;
        else
        {
          temp->right = newNode;
          break;
        }
      }
    }
  }
}

void writeToFile(Star *root)
{
  if (root != NULL)
  {
    ofstream opf;
    opf.open("newStar.txt", ios::app);

    if (opf.is_open())
    {
      writeToFile(root->left);
      opf << "******************************************************" << endl;
      opf << "ID of star: " << root->starID << endl;
      opf << "Name of the Star: " << root->name << endl;
      opf << "Color of the Star: " << root->color << endl;
      opf << "mass of the Star: " << root->mass << endl;
      opf << "Temprature of the star: " << root->temprature << endl;
      opf << "Luminousity of the star: " << root->luminousity << endl;
      opf << "******************************************************" << endl;
      opf << endl
          << endl;
      writeToFile(root->right);
      cout << "\nStar written to file succefully";
      opf.close();
    }
    else
      cout << "\nError while opening the file" << endl;
  }
}

void preOrderTraversal(struct Star *temp)
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;

  if (temp != NULL)
  {

    cout << endl;
    cout << "the ID of the star is: " << temp->starID << endl;
    cout << "the name of the star is: " << temp->name << endl;
    cout << "the color of the star is: " << temp->color << endl;
    cout << "the mass of the star is: " << temp->mass << endl;
    cout << "the temprature of the star is: " << temp->temprature << endl;
    cout << "the luminousity of the star is: " << temp->luminousity << endl;
    cout << endl;
    preOrderTraversal(temp->left);
    preOrderTraversal(temp->right);
  }
}

void postOrderTraversal(struct Star *temp)
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;
  if (temp != NULL)
  {
    postOrderTraversal(temp->left);
    postOrderTraversal(temp->right);
    cout << endl;
    cout << "the ID of the star is: " << temp->starID << endl;
    cout << "the name of the star is: " << temp->name << endl;
    cout << "the color of the star is: " << temp->color << endl;
    cout << "the mass of the star is: " << temp->mass << endl;
    cout << "the temprature of the star is: " << temp->temprature << endl;
    cout << "the luminousity of the star is: " << temp->luminousity << endl;
    cout << endl;
  }
}

void displayMinimumNode()
{
  if (root == NULL)
  {
    cout << "sorry data is empty." << endl;
    return;
  }
  else
  {
    Star *temp = root;
    while (temp->left != NULL)
      temp = temp->left;
    cout << endl;
    cout << "*****************************minimum star name*******************************" << endl;
    cout << "the name of the mimimum star is: " << temp->name << endl;
    cout << "the ID of the star is: " << temp->starID << endl;
    cout << "the color of this star is: " << temp->color << endl;
    cout << "the mass of this star is: " << temp->mass << endl;
    cout << "the temprature of this star is: " << temp->temprature << endl;
    cout << "the luminousity of this star is: " << temp->luminousity << endl;
    cout << endl;
    cout << "************************************************************" << endl;
    return;
  }
}

void displayMaximumNode()
{

  if (root == NULL)
  {
    cout << "sorry data is empty." << endl;
    return;
  }

  else
  {
    Star *temp = root;
    while (temp->right != NULL)
      temp = temp->right;
    cout << endl;
    cout << "***************************maximum star name*********************************" << endl;
    cout << "the name of the maximum star is: " << temp->name << endl;
    cout << "the ID of the star is: " << temp->starID << endl;
    cout << "the color of this star is: " << temp->color << endl;
    cout << "the mass of this star is: " << temp->mass << endl;
    cout << "the temprature of this star is: " << temp->temprature << endl;
    cout << "the luminousity of this star is: " << temp->luminousity << endl;
    cout << endl;
    cout << "************************************************************" << endl;
    return;
  }
}
int searchforname(struct Star *temp, char name[])
{
  if (root == NULL)
    return -1;
  if (temp != NULL)
  {
    if (strcmp(temp->name, name) == 0)
      return 0;
    else
      return -1;
    searchforname(temp->left, name);
    searchforname(temp->right, name);
  }
}
int searchforid(struct Star *temp, int id)
{
  if (root == NULL)
    return -1;
  if (temp != NULL)
  {
    if (temp->starID == id)
      return 0;
    else
      return -1;
    searchforid(temp->left, id);
    searchforid(temp->right, id);
  }
}
void searchbyname(struct Star *temp, char starname[20])
{

  if (root == NULL)
    cout << "sorry data is empty." << endl;

  if (temp != NULL)
  {

    if (strcmp(starname, temp->name) == 0)
    {
      cout << "*******************************************************" << endl;
      cout << "yes the star is in the bst. with information: " << endl;
      cout << "*******************************************************" << endl;
      cout << "*the name of the star is: " << temp->name << endl;
      cout << "the ID of the star is: " << temp->starID << endl;
      cout << "the color of the star is: " << temp->color << endl;
      cout << "the mass of the star is: " << temp->mass << endl;
      cout << "the temprature of the star is: " << temp->temprature << endl;
      cout << "the luminousity of the star is: " << temp->luminousity << endl;
      cout << endl;
    }
    if (strcmp(starname, temp->name) < 0)
      searchbyname(temp->left, starname);
    if (strcmp(starname, temp->name) > 0)
      searchbyname(temp->right, starname);
  }
  else
  {
    cout << "*******************************************************" << endl;
    cout << "Star is not found." << endl;
    cout << "*******************************************************" << endl;
  }
}

void searchbyid(struct Star *temp, int id)
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;

  if (temp != NULL)
  {
    if (temp->starID == id)
    {
      cout << "*******************************************************" << endl;
      cout << "yes the star is in the bst. with information: " << endl;
      cout << "*******************************************************" << endl;
      cout << "*the ID of the star is: " << temp->starID << endl;
      cout << "the name of the star is: " << temp->name << endl;
      cout << "the color of the star is: " << temp->color << endl;
      cout << "the mass of the star is: " << temp->mass << endl;
      cout << "the temprature of the star is: " << temp->temprature << endl;
      cout << "the luminousity of the star is: " << temp->luminousity << endl;
      cout << endl;
      searchbyid(temp->left, id);
      searchbyid(temp->right, id);
      return;
    }
    else
    {
      searchbyid(temp->left, id);
      searchbyid(temp->right, id);
      return;
    }
  }
  // cout<<"sorry id is not found in the bst";
}

void searchbycolor(struct Star *temp, char color[])
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;

  if (temp != NULL)
  {
    if (strcmp(temp->color, color) == 0)
    {
      cout << "*******************************************************" << endl;
      cout << "yes the star is in the bst. with information: " << endl;
      cout << "*******************************************************" << endl;
      cout << "*the color of the star is: " << temp->color << endl;
      cout << "the id of the star is: " << temp->starID << endl;
      cout << "the name of the star is: " << temp->name << endl;
      cout << "the mass of the star is: " << temp->mass << endl;
      cout << "the temprature of the star is: " << temp->temprature << endl;
      cout << "the luminousity of the star is: " << temp->luminousity << endl;
      cout << endl;
      searchbycolor(temp->left, color);
      searchbycolor(temp->right, color);
      return;
    }
    else
    {
      searchbycolor(temp->left, color);
      searchbycolor(temp->right, color);
      return;
    }
  }
  // cout<<"sorry id is not found in the bst";
}

void searchbymass(struct Star *temp, int mass)
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;
  if (temp != NULL)
  {
    if (temp->mass == mass)
    {
      cout << "*******************************************************" << endl;
      cout << "yes the star is in the bst. with information: " << endl;
      cout << "*******************************************************" << endl;
      cout << "*the mass of the star is: " << temp->mass << endl;
      cout << "the id of the star is: " << temp->starID << endl;
      cout << "the name of the star is: " << temp->name << endl;
      cout << "the color of the star is: " << temp->color << endl;
      cout << "the temprature of the star is: " << temp->temprature << endl;
      cout << "the luminousity of the star is: " << temp->luminousity << endl;
      cout << endl;
      searchbymass(temp->left, mass);
      searchbymass(temp->right, mass);
      return;
    }
    else
    {
      searchbymass(temp->left, mass);
      searchbymass(temp->right, mass);
      return;
    }
  }
  // cout<<"sorry id is not found in the bst";
}

void searchbytemprature(struct Star *temp, int temprature)
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;

  if (temp != NULL)
  {
    if (temp->temprature == temprature)
    {
      cout << "*******************************************************" << endl;
      cout << "yes the star is in the bst. with information: " << endl;
      cout << "*******************************************************" << endl;
      cout << "*the temprature of the star is: " << temp->temprature << endl;
      cout << "the id of the star is: " << temp->starID << endl;
      cout << "the name of the star is: " << temp->name << endl;
      cout << "the color of the star is: " << temp->color << endl;
      cout << "the mass of the star is: " << temp->mass << endl;
      cout << "the luminousity of the star is: " << temp->luminousity << endl;
      cout << endl;
      searchbytemprature(temp->left, temprature);
      searchbytemprature(temp->right, temprature);
      return;
    }
    else
    {
      searchbytemprature(temp->left, temprature);
      searchbytemprature(temp->right, temprature);
      return;
    }
  }
  // cout<<"sorry id is not found in the bst";
}

void searchbyluminousity(struct Star *temp, int luminousity)
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;

  if (temp != NULL)
  {
    if (temp->luminousity == luminousity)
    {
      cout << "*******************************************************" << endl;
      cout << "yes the star is in the bst. with information: " << endl;
      cout << "*******************************************************" << endl;
      cout << "*the luminousity of the star is: " << temp->luminousity << endl;
      cout << "the id of the star is: " << temp->starID << endl;
      cout << "the name of the star is: " << temp->name << endl;
      cout << "the color of the star is: " << temp->color << endl;
      cout << "the mass of the star is: " << temp->mass << endl;
      cout << "the temprature of the star is: " << temp->temprature << endl;
      cout << endl;
      searchbyluminousity(temp->left, luminousity);
      searchbyluminousity(temp->right, luminousity);
      return;
    }
    else
    {
      searchbyluminousity(temp->left, luminousity);
      searchbyluminousity(temp->right, luminousity);
      return;
    }
  }
  // cout<<"sorry id is not found in the bst";
}
int countnodes(struct Star *root)
{
  if (root != NULL)
  {
    countnodes(root->left);
    count++;
    countnodes(root->right);
  }
  return count;
}

void deleteminimum()
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;

  Star *temp = root;
  while (temp->left->left != NULL)
  {
    temp = temp->left;
  }
  delete temp->left;
  temp->left = NULL;
}

void deletemaximum()
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;

  Star *temp = root;
  while (temp->right->right != NULL)
  {
    temp = temp->right;
  }
  delete temp->right;
  temp->right = NULL;
}

void deleteroot()
{
  if (root == NULL)
    cout << "sorry data is empty." << endl;

  Star *temp = root;
  Star *temp1 = root;
  if (temp->left != NULL)
  {
    temp = temp->left;
    while (temp->right != NULL)
    {
      temp = temp->right;
    }
    temp->right = temp1->right;
    root = root->left;
    temp1->right = NULL;
    cout << "ROOT DELETED SUCCESSFULLY!" << endl;
    delete temp1;
  }
  else
  {
    root = root->right;
    temp1->right = NULL;
    cout << "ROOT DELETED SUCCESSFULLY!" << endl;

    delete temp1;
  }
}

int height(Star *node)
{
  if (node == NULL)
    return 0;
  else
    return node->height;
}
int balanceFactor(Star *node)
{
  return height(node->right) - height(node->left);
}
void updateHeight(Star *node)
{
  node->height = std::max(height(node->left), height(node->right)) + 1;
}
Star *rightRotate(Star *y)
{
  Star *x = y->left;
  Star *t2 = x->right;

  x->right = y;
  y->left = t2;

  updateHeight(y);
  updateHeight(x);

  return x;
}
Star *leftRotate(Star *x)
{
  Star *y = x->right;
  Star *t2 = y->left;

  y->left = x;
  x->right = t2;

  updateHeight(x);
  updateHeight(y);

  return y;
}
Star *convertToAVL(Star *node)
{
  if (!node)
    return node;
  int bf = balanceFactor(node);
  if (bf > 1)
  {
    if (balanceFactor(node->right) < 0)
      node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  else if (bf < -1)
  {
    if (balanceFactor(node->left) > 0)
      node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  updateHeight(node);
  node->left = convertToAVL(node->left);
  node->right = convertToAVL(node->right);

  return node;
}

void exitbst()
{
  system("cls");
  cout << endl
       << "\t\t\tTHANK YOU FOR VISITING! GOODBYE" << endl
       << "\t\t";
  exit(1);
}
void continueornot()
{
  char a;
manipulate:
  cout << "Continue to manupilate bst(Go to main menu) (y/n):";
  cin >> a;
  if (a == 'Y' || a == 'y')
    main();
  else if (a == 'N' || a == 'n')
    exitbst();
  else
  {
    cout << "\t\t\t\tINVALID INPUT PICK EITHER Y OR N" << endl;
    goto manipulate;
  }
}

bool isNumber(char s[])
{
  int x = strlen(s);
  for (int i = 0; i < x; i++)
    if (isdigit(s[i]) == false)
      return false;

  return true;
}
