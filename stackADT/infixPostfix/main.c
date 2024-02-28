    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
     
    struct Stack{
        int size;
        int top;
        char *S;
    };
     
    void push(struct Stack *st, char x){
        if(st->top == st->size - 1)
            printf("Stack Overflow\n");
        else{
            st->top++;
            st->S[st->top] = x;
        }
    }
     
    char pop(struct Stack *st){
        if(st->top == -1)
            printf("Stack Underflow");
        else{
            return st->S[st->top--];
        }
    }
     
    int isOperand(char x){
        if(x == '+' || x == '-' || x == '/' || x == '*' || x =='(' || x ==')' || x == '^' )
            return 0;
        else
            return 1;
    }
     
    int outPre(char x){
        if(x == '+' || x == '-')
            return 1;
        else if( x == '/' || x == '*')
            return 3;
        else if(x == '^')
            return 6;
        else if(x == '(')
            return 7;
        else if(x == ')')
            return 0;
        else
            return -1;
    }
     
    int inPre(char x){
        if(x == '+' || x == '-')
            return 2;
        else if( x == '/' || x == '*')
            return 4;
        else if(x == '^')
            return 5;
        else if(x == '(')
            return 0;
        else
            return -1;
    }
     
    char * InToPost(char *infix){
        int len = strlen(infix);
        int i = 0, j = 0;
        struct Stack st;
        char *postfix = (char *)malloc((len + 1)* sizeof(char));
        st.size = len;
        st.top = -1;
        st.S = (char *)malloc(st.size * sizeof(char));
        
        while(infix[i] != '\0'){
            if(isOperand(infix[i])){
                postfix[j++] = infix[i++];
            }
            else{
                if(st.top == -1 || outPre(infix[i]) > inPre(st.S[st.top]))
                    push(&st, infix[i++]);
                else{
                    if(outPre(infix[i]) == inPre(st.S[st.top])){
                        pop(&st);
                        i++;
                    }
                    else
                        postfix[j++] = pop(&st);
                }
            }
        }
        while(st.top != -1){
            postfix[j++] = pop(&st);
        }
        
        postfix[j] = '\0';
        return postfix;
        
        
    }
     
    void main(){
        char *infix = "((a+b)*c)-d^e^f";
        
        char *postfix = InToPost(infix);
        
        printf("\n%s",postfix);
    }