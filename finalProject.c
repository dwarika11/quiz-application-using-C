#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
 void displayQuizstatistics();
void  displayquestionA();//nitesh
void   displayQuestionsB();//mukesh
void displayQuesstionsC();//mukesh
 void displayQuestionsD();//mukesh
     void EnterStudentDetails();//nitesh
     void SearchQuestion();//laxmi
     float calculatePercentage(int score,int total);//ayushi
     void DisplayAnswerAnalysis();
char* checkAnswer(int index);//this function returns a pointer to the charcater which can point to the string  //dwarika
void displayMenu();//nitesh
void DisplayResult();
char* calculateGrade(float percentage);//ayushi  //here is the change
void selectQuizCategories();//dwarika
void StartQuiz();
void Exit();//anshuman
int show;
int j;
char answer;
char correctanswer[10];
int a=0;//to check that user had enteres his details or not
int attendquiz=0;
int quizcate=0;//to take the input of quiz category type
 char name[30],course[50];//to take input of name and course from the user
 int rollno;//to take input of rollno from the user
 int totalques=10;// the no of total questions
 int correct=0;// no of correct answers
 int score=0;//score of the user
int wrong=0;// no of wrong answer
char studentanswer[10]; //student answer
float percent;// to catch the function call of the calculatepercentage
char *grade;// to catch the fuction call of char calculategrade   //here is the change

    char questionsA[10][100]={"1. Which of the following is the correct format specifier for unsigned int in C?",
"2. Which of the following is NOT a valid storage class in C?",
"3. What is the size of char data type in C (on most modern systems)?",
"4. Which function is used to dynamically allocate memory in C?",
"5. Which operator has the highest precedence in C?",
"6. Which of the following is used to end a string in C?","7. Which header file is required for printf() function?",
"8. which of the following function is used to print output on the screen",
"9. which of the following header file is used to apply string functions",
"10. which of the following specifier is used to take input of the character"};

 char questionsB[10][100]={"1. What is the full form of CPU?",
        "2. Which device is used to enter data into a computer?",
        "3. Which device is used to display output?",
        "4. What is the brain of a computer?",
        "5. Which memory is temporary?",
        "6. What is the full form of RAM?",
        "7. Which device is used to store data permanently?",
        "8. Which of these is an operating system?",
        "9. What is the full form of ROM?",
        "10. Which device is used to print documents?"
};
char questionsC[10][100]={
        "1. What is the capital of India?",
        "2. Who is known as the Father of the Nation in India?",
        "3. Which is the largest planet in our Solar System?",
        "4. How many states are there in India?",
        "5. Which is the national animal of India?",
        "6. Which is the longest river in India?",
        "7. Who was the first Prime Minister of India?",
        "8. Which is the smallest state of India by area?",
        "9. In which year did India get independence?",
        "10. Which is the national flower of India?"
    };
      char questionsD[10][100]={
        "1. What is a programming language?",
        "2. What is a variable?",
        "3. Which symbol is used for assignment in C?",
        "4. Which statement is used for decision making?",
        "5. Which loop executes at least once?",
        "6. What is an algorithm?",
        "7. What is a flowchart?",
        "8. Which loop is commonly used when the number of iterations is known?",
        "9. What is debugging?",
        "10. What is a compiler?"
    };
void main(){//arjun
    int code;
    printf("\t\t\t\t\t\tOnline Quiz And Result System In C\n");
    printf("\t\t\t\t\t\t==================================\n");
    printf("\t=>Dear user! Have you want to see menu on the screen.if yes then press 1 to see menu. :");
    scanf("%d",&code);
   switch(code){
    case 1:{
        displayMenu();
        break;
    }
    default:{
        printf("invalid input! Please try again later.\n ");
        printf("you press %d and there is no any options avialable for this input. ",code);
        break;
    }
   }
}
void displayMenu(){
    int code;
    do{
    printf("\n\t\t\t\t\t\tMenu\n");
    printf("\t\t\t\t\t\t****\n");
    printf("\t1) Enter Student Details\n");
    printf("\t2) Select Quiz Category\n");
    printf("\t3) Start Quiz\n");
    printf("\t4) Display Answer Analysis\n");
    printf("\t5) Search Question\n");
    printf("\t6) Display Result\n");
    printf("\t7) Display Quiz Statistics\n");
    printf("\t8) Exit\n\n");
    printf("\t=>Dear user please enter your choice in the form of numbers: ");
    scanf("%d",&code);
    switch(code){
        case 1:{
            EnterStudentDetails();
         break;
        }
        case 2:{
            selectQuizCategories();
           break;
        }
        case 3:{
            StartQuiz();
            break;
        }
        case 4:{
            DisplayAnswerAnalysis();
            break;
        }
        case 5:{
            SearchQuestion();
           break;
        }
        case 6:{
            DisplayResult();
               break;
        }
        case 7:{
            displayQuizstatistics();
              break;
        }
        case 8:{
            Exit();
             break;
        }
        default:{
            printf("invlaid choice");
            break;
        }
    }
    printf("press any key to continue");
    getch();
}
while(code!=8);
}


void selectQuizCategories(){
     printf("\n\t\t\t\t\t\tQuiz Categories\n");
   printf("\t\t\t\t\t\t*****************\n");
   // EnterStudentDetails();
   if(quizcate==0){//here is the change
       printf("\n\t 1.C Programming\n");
       printf("\t 2.C Computer Fundamentals\n");
       printf("\t 3.General Knowledge\n");
       printf("\t 4.C Programming Basic\n");
       printf("Please Enter Your Choise :");
       scanf("%d",&quizcate);

        }else{
            printf("option %d was already selected.please move to the another one.\n",quizcate);//here is the change
        }
    }


void StartQuiz(){
   // displayCategories();
   int i;
    if(quizcate==0){
    printf("dear user please select the quiz categories\n");
    printf(" and if you want to select the quiz category now then press 2  to continue");
    scanf("%d",&i);
    if(i==2){
    selectQuizCategories();
}else{
    printf("you have selected %d and there is no option available for 3: \n",i);
}
    }
   else if(attendquiz==0){{//here is the change
    switch(quizcate){
        case 1:{
             printf("\n\t\t\t\t\t\tQuiz On C Programming\n");
             printf("\t\t\t\t\t\t**********************\n");
         displayquestionA();
        attendquiz++;
        break;
        }
        case 2:{
             printf("\n\t\t\t\t\t\tQuiz On Computer Fundamentals\n");
             printf("\t\t\t\t\t\t*****************************\n");
            displayQuestionsB();
         attendquiz++;
         break;
        }
        case 3:{
             printf("\n\t\t\t\t\t\tQuiz On General Knowledge\n");
             printf("\t\t\t\t\t\t*************************\n");
            displayQuesstionsC();
          attendquiz++;
          break;
        } case 4:{
             printf("\n\t\t\t\t\t\tQuiz On Programming Basics\n");
             printf("\t\t\t\t\t\t**************************\n");
            displayQuestionsD();
           attendquiz++;
           break;
        }
        default:{
            printf("Dear user please select the valid quiz category.\n");
            break;
        }
    }
}
}else{
    printf("you have attended the quiz please move to the another one.\n");//here is the change
}
}


void displayquestionA(){


char options[10][4][30]={{"A) %d","B) %u","C) %ld","D) %lu"},
{"A) auto","B) register","C) static","D) volatile"},
{"A) 1 bytes","B) 2 bytes","C) 4 bytes","D) depends on the compiler"},
{"A) malloc()","B) alloc()","C) memalloc()","D) calloc()"},
{"A) ++","B) *(multiplication)","C) &&","D) ="},
{"A) \\n","B) \\0","B) null","D) Eof"},
{"A) string.h","B) stdio.h","C) math.h","D) ctype.h"},
{"A) printf()","B) scanf()","C) gets()","D)calloc()"},
{"A) #include<string.h>","B) #include<stdio.h>","C) #include<ctype.h>","D) #include<conio.h>"},
{"A) %c","B) %d","C) %s","D) %f"}
};

correctanswer[0]='B';
correctanswer[1]='D';
correctanswer[2]='A';
correctanswer[3]='A';
correctanswer[4]='A';
correctanswer[5]='B';
correctanswer[6]='B';
correctanswer[7]='A';
correctanswer[8]='A';
correctanswer[9]='A';


for(show=0;show<10;show++){
    printf("%s\n",questionsA[show]);
  for(j=0;j<4;j++){
    printf("%s\n",options[show][j]);
  }
  printf("dear user please enter your choice");
  scanf(" %c",&answer);
  answer=toupper(answer);
  studentanswer[show]=answer;
  if(studentanswer[show]==correctanswer[show]){
    printf("\n\t*your answer is correct");
    correct++;
    score++;
  }else{
    printf("\n\t*your answer is incorrect");
    wrong++;
  }
  printf("\n\n\t*correct answer is %c",correctanswer[show]);
  printf("\n\n\t*your selected options is %c\n\n",answer);
}
printf("no of the correct answer is %d\n",correct);
printf("no of the incorrect answer is %d\n",wrong);
}
void displayQuestionsB(){
   correctanswer[0]='A';
   correctanswer[1]='B';
   correctanswer[2]='C';
   correctanswer[3]='B';
   correctanswer[4]='B';
   correctanswer[5]='B';
   correctanswer[6]='B';
   correctanswer[7]='A';
   correctanswer[8]='A';
   correctanswer[9]='C';





    char options[10][4][30]={
       {"A) Central Processing Unit","B) Computer Personal Unit","C) Central Program Unit","D) Control Processing Unit"},
        {"A) Monitor","B) Keyboard","C) Printer","D) Speaker"},
        {"A) Keyboard","B) Mouse","C) Monitor","D) Scanner"},
        {"A) Monitor","B) CPU","C) Keyboard","D) Printer"},
        {"A) ROM","B) RAM","C) Hard Disk","D) CD"},
        {"A) Read Access Memory","B) Random Access Memory","C) Run Access Memory","D) Rapid Access Memory"},
        {"A) RAM","B) Hard Disk","C) Cache","D) Register"},
        {"A) Windows","B) Keyboard","C) Mouse","D) Printer"},
        {"A) Read Only Memory","B) Random Only Memory","C) Read Open Memory","D) Run Only Memory"},
        {"A) Scanner","B) Monitor","C) Printer","D) Keyboard"}};

        for(show=0;show<10;show++){
    printf("%s\n",questionsB[show]);
  for(j=0;j<4;j++){
    printf("%s\n",options[show][j]);
  }
  printf("\ndear user please enter your choice: ");
  scanf(" %c",&answer);
  answer=toupper(answer);
  studentanswer[show]=answer;
  if(studentanswer[show]==correctanswer[show]){
    printf("\n\t*your answer is correct");
    correct++;
    score++;
  }else{
    printf("\n\t*your answer is incorrect");
    wrong++;
  }
  printf("\n\n\t*correct answer is %c",correctanswer[show]);
  printf("\n\n\t*your selected options is %c\n\n",answer);
}
printf("no of the correct answer is %d\n",correct);
printf("no of the incorrect answer is %d\n",wrong);
    }
void displayQuesstionsC(){
  correctanswer[0]='B';
  correctanswer[1]='A';
  correctanswer[2]='C';
  correctanswer[3]='B';
  correctanswer[4]='B';
  correctanswer[5]='A';
  correctanswer[6]='B';
  correctanswer[7]='A';
  correctanswer[8]='C';
  correctanswer[9]='B';


    char options[10][4][30]={
         {"A) Mumbai","B) New Delhi","C) Kolkata","D) Chennai"},
        {"A) Mahatma Gandhi","B) Jawaharlal Nehru","C) Sardar Patel","D) Subhash Chandra Bose"},
        {"A) Earth","B) Mars","C) Jupiter","D) Venus"},
        {"A) 26","B) 28","C) 29","D) 30"},
        {"A) Lion","B) bengal Tiger","C) Elephant","D) Leopard"},
        {"A) Ganga","B) Yamuna","C) Godavari","D) Narmada"},
        {"A) Mahatma Gandhi","B) Jawaharlal Nehru","C) Rajendra Prasad","D) Lal Bahadur Shastri"},
        {"A) Goa","B) Sikkim","C) Kerala","D) Tripura"},
        {"A) 1945","B) 1946","C) 1947","D) 1950"},
        {"A) Rose","B) Lotus","C) Sunflower","D) Jasmine"}
    };
     for(show=0;show<10;show++){
    printf("%s\n",questionsC[show]);
  for(j=0;j<4;j++){
    printf("%s\n",options[show][j]);
  }
  printf("dear user please enter your choice");
  scanf(" %c",&answer);
  answer=toupper(answer);
  studentanswer[show]=answer;
  if(studentanswer[show]==correctanswer[show]){
    printf("\n\t*your answer is correct");
    correct++;
    score++;
  }else{
    printf("\n\t*your answer is incorrect");
    wrong++;
  }
  printf("\n\n\t*correct answer is %c",correctanswer[show]);
  printf("\n\n\t*your selected options is %c\n\n",answer);
}
printf("no of the correct answer is %d\n",correct);
printf("no of the incorrect answer is %d\n",wrong);


}
void displayQuestionsD(){
 correctanswer[0]='A';
 correctanswer[1]='B';
 correctanswer[2]='B';
 correctanswer[3]='A';
 correctanswer[4]='C';
 correctanswer[5]='B';
 correctanswer[6]='B';
 correctanswer[7]='B';
 correctanswer[8]='B';
 correctanswer[9]='A';


    char options[10][4][30]={
        {"A) Software language","B) Hardware","C) Operating system","D) Database"},
        {"A) Fixed value","B) Named memory location","C) Function","D) Operator"},
        {"A) ==","B) =","C) !=","D) >"},
        {"A) if","B) printf","C) scanf","D) return"},
        {"A) for","B) while","C) do-while","D) switch"},
        {"A) Computer virus","B) Step-by-step solution","C) Hardware","D) Database"},
        {"A) Program code","B) Diagram of a process","C) Operating system","D) Memory"},
        {"A) if","B) for","C) switch","D) goto"},
        {"A) Writing code","B) Finding and fixing errors","C) Installing software","D) Saving files"},
        {"A) Translates source code","B) Stores data","C) Prints documents","D) Creates hardware"}
    };

      for(show=0;show<10;show++){
    printf("%s\n",questionsD[show]);
  for(j=0;j<4;j++){
    printf("%s\n",options[show][j]);
  }
  printf("dear user please enter your choice");
  scanf(" %c",&answer);
  answer=toupper(answer);
  studentanswer[show]=answer;
  if(studentanswer[show]==correctanswer[show]){
    printf("\n\t*your answer is correct");
    correct++;
    score++;
  }else{
    printf("\n\t*your answer is incorrect");
    wrong++;
  }
  printf("\n\n\t*correct answer is %c",correctanswer[show]);
  printf("\n\n\t*your selected options is %c\n\n",answer);
}
printf("no of the correct answer is %d\n",correct);
printf("no of the incorrect answer is %d\n",wrong);
}

char* checkAnswer(int index){//this is the way by which we can return a string literal
       for(int i=0;i<9;i++){
           if(studentanswer[index]==correctanswer[index]){
            return "Correct";
           }
           else{
            return "wrong";
           }
       }
}

void DisplayResult(){
     printf("\n\t\t\t\t\t\tResult\n");
     printf("\t\t\t\t\t\t*******\n");
    if(a==0){
        printf("Dear user please enter student details\n");
        if(quizcate==0){
            printf("and also select the quiz category\n");
            if(attendquiz==0){
                printf("and also attend the quiz from option 3 to print the result\n");
            }
        }else if(attendquiz==0){
            printf("please attend the questions to print the whole result\n");
        }
    }else if(quizcate==0){
        printf("please select the quiz category\n");
        if(attendquiz==0){
            printf("and also attend the quiz section\n");
        }
    }else if(attendquiz==0){
        printf("please attend the quiz section to print the result\n");
    }
    else{
       printf("Student Name    :%s\n",name);
       printf("Roll Number     :%d\n",rollno);
       printf("Quiz Category   :%d\n",quizcate);
       printf("Total Questions :%d\n",totalques);
       printf("Correct Answer  :%d\n",correct);
       printf("Wrong Answer    :%d\n",wrong);
       printf("Score  : %d/%d\n",score,totalques);
       percent=calculatePercentage(score,totalques);
       printf("Percentage : %f%%\n",percent);
       grade=calculateGrade(percent);
       printf("Grade  :%s\n",grade);//here is the change
    }
}

void DisplayAnswerAnalysis(){
     printf("\n\t\t\t\t\t\tAnswer Analysis\n");
     printf("\t\t\t\t\t\t***************\n");
    if(quizcate==0){
        printf("Dear user please select the quiz category to display answer analysis\n");//here is the chnage in statement
        if(attendquiz==0){
            printf("and also attend the quiz to continue\n");
        }
    }else if(attendquiz==0){
            printf("you have selected the quiz category but not attend the quiz please attend the quiz to display answer analysis\n");
        } else{
         printf("\t\t\t\t\t\tAnswer Analysis\n");
         printf("\t\t\t\t\t\t===============\n");
         printf("\nques.no.\tyour answer\tcorrect answer\tresult\n");
         printf("------------------------------------------------\n");


         for(int i=0;i<10;i++){
              char *check=checkAnswer(i);//the fuction returns a pointer to a charcter which can point to the string
         printf("%d\t\t%c\t\t%c\t\t%s\n",i+1,studentanswer[i],correctanswer[i],check);//change
         }
        }
}

void SearchQuestion(){
  int choice;
    int found=0;
    char keyword[50];//chnage
    char temp[200];//change
     printf("\n\t\t\t\t\t\tSearch Question\n");
     printf("\t\t\t\t\t\t******************\n");
     printf("dear user please select a category in whcih you want to search\n");
     printf("1.) C programming\n");
     printf("2.) Computer fundamentals\n");
     printf("3.) General Knowledge\n");
     printf("4.) Programming Basics\n");
     printf("5.) Select All Category\n");
     scanf("%d",&choice);
      printf("dear  user please enter a keyword: ");
             scanf("%s",&keyword);
             strupr(keyword);
     if(choice==1||choice==5){
             printf("\n\t\t\t\t\t\tquestions in c programming\n");
             printf("\t\t\t\t\t\t**************************\n");
             for(int i=0;i<10;i++){
                 strcpy(temp,questionsA[i]);
                 strupr(temp);
               char *result=strstr(temp,keyword);//strstr function returns a pointer value and hence we have to store it in a pointer
               //  if(strstr(temp,keyword)!=0){
               if(result!=0){
                    printf("%s\n",questionsA[i]);
                    found=1;
                 }
             }
              if(found==0){
        printf("no matching found");
     }else{
        printf("search completed succesfully in first category");
     }

     }
     if(choice==2||choice==5){

             printf("\n\t\t\t\t\t\tquestions in computer fundamental\n");
             printf("\t\t\t\t\t\t*********************************\n");
             for(int i=0;i<10;i++){
                 strcpy(temp,questionsB[i]);
                 strupr(temp);
               char *result=strstr(temp,keyword);//strstr function returns a pointer value and hence we have to store it in a pointer
               //  if(strstr(temp,keyword)!=0){
               if(result!=0){
                    printf("%s\n",questionsB[i]);
                    found=1;
                 }
             }
              if(found==0){
        printf("no matching found");
     }else{
        printf("search completed succesfully in second category");
     }

     }
     if(choice==3||choice==5){

             printf("\n\t\t\t\t\t\tquestions in general knowledge\n");
             printf("\t\t\t\t\t\t******************************\n");
             for(int i=0;i<10;i++){
                 strcpy(temp,questionsC[i]);
                 strupr(temp);
               char *result=strstr(temp,keyword);//strstr function returns a pointer value and hence we have to store it in a pointer
               //  if(strstr(temp,keyword)!=0){
               if(result!=0){
                    printf("%s\n",questionsC[i]);
                    found=1;
                 }
             }
              if(found==0){
        printf("no matching found");
     }else{
        printf("search completed succesfully in third category");
     }
     }
     if(choice==4||choice==5){

             printf("\n\t\t\t\t\t\tquestions in  programming basics\n");
             printf("\t\t\t\t\t\t*********************************\n");
             for(int i=0;i<10;i++){
                 strcpy(temp,questionsD[i]);
                 strupr(temp);
               char *result=strstr(temp,keyword);//strstr function returns a pointer value and hence we have to store it in a pointer
               //  if(strstr(temp,keyword)!=0){
               if(result!=0){
                    printf("%s\n",questionsD[i]);
                    found=1;
                 }
             }
              if(found==0){
        printf("no matching found");
     }else{
        printf("search completed succesfully fourth category");
     }
     }
      if(choice>5||choice<1){
      printf("please select a valid category\n");
     }


}


float calculatePercentage(int score,int total){
               float percentage;
               percentage=(score*100)/total;
               return percentage;
}

char* calculateGrade(float percentage){
    if(percentage<50){
        return "F";
    }else if(percentage>=50&&percentage<=59){
        return "D";
    }else if(percentage>=60&&percentage<=69){
        return "C";
    }else if(percentage>=70&&percentage<=79){
        return "B";
    }else if(percentage>=80&&percentage<=89){
           return "A";
    }else if(percentage>=90&&percentage<=100){
        return "A+";
    }

}
 void EnterStudentDetails(){
     int i;
     if(a==0){
        for(int b=1;b<=1;b++){
   printf("\n\t\t\t\t\t\tEnter Student Details\n");
   printf("\t\t\t\t\t\t************************\n");
   printf("=> Dear user please enter your name: ");
   scanf(" %[^\n]", name);
    printf("\n=>dear user please enter your course: ");
    scanf(" %[^\n]", course);
    printf("\n=>dear user please enter your roll no: ");
    scanf("%d",&rollno);
    printf("\n\nCongratulations! you have fill the details successfully.\n\n");
    a++;
    if(quizcate==0){
        printf("if you want to select the quiz category now then press 2 and if you want to return to the main menu then press other then 2: \n");
        scanf("%d",&i);
        if(i==2){
        selectQuizCategories();
       }else{
            printf("you have selected %d and there is no option available for this input\n ",i);
            break;
     }

   if(attendquiz==0){
    printf("if you want to start the quiz now then press 3  to continue: \n");
   printf("and if you want to return to the main menu then press any key to continue");
     scanf("%d",&i);
    if(i==3){
     StartQuiz();
    }else{
       printf("you have selected %d and there is no option available for this input: \n",i);
       break;
    }
      printf("if you want to see the answer analysis then press 4 to continue: ");
       scanf("%d",&i);
       if(i==4){
    DisplayAnswerAnalysis();
   }
   else{
    printf("you have selected %d and there is no option available for this input: \n",i);
    break;
   }
    }
    }

}}else{
        printf("you have entered your details please move to the another one.\n");//here is the change

    }
 }
 void Exit(){
     printf("\n\t\t\t\t\t\tExit\n");
     printf("\t\t\t\t\t\t******\n");
    printf("Dear user!you have not attend the quiz. So there is no any results declared for you. Thank you!for using this service\n");
 }
 void displayQuizstatistics(){
     printf("\n\t\t\t\t\t\tQuiz Statistics\n");
     printf("\t\t\t\t\t\t***************\n");
    if(quizcate==0){
        printf("dear user please select the quiz category to display the quiz statistics\n");
        if(attendquiz==0){
            printf("and also attend the quiz to display quiz statistics\n");
        }}else if(attendquiz==0){
            printf("dear user please attend the quiz:\n");
        }else{
        printf("Total questions: %d\n",totalques);
        printf("Correct Answer: %d\n",correct);
        printf("Wrong Answer : %d\n",wrong);
        printf("score : %d\n",score);
        percent=calculatePercentage( score, totalques);
        printf("Percentage : %f%%\n",percent);
        grade=calculateGrade(percent);
        printf("Grade : %s\n",grade);

 }
}
