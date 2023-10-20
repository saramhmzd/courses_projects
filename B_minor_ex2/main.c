#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int num_line=1;
FILE *fd;
FILE *fo;
int c;

void remove_comments(){
    int l = fgetc(fd);
    while(1){
        if(l == '*'){
            l=fgetc(fd);
            if(l=='/'){
                l=fgetc(fd);
                break;
            }
        }
        l=fgetc(fd);
    }
    ungetc(l,fd);
}

void remove_comment(){
    int l = fgetc(fd);
    while(l!=10){
            l=fgetc(fd);
    }
    ungetc(l,fd);
}


int check_array(){
    int r1,r2,a2,y;
    int next;
    r1=fgetc(fd);
    r2=fgetc(fd);
    a2=fgetc(fd);
    y=fgetc(fd);
    next=fgetc(fd);
    if(r1=='r' && r2=='r' && a2=='a' && y=='y' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"array\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(y,fd);
        ungetc(a2,fd);
        ungetc(r2,fd);
        ungetc(r1,fd);
        return 0;
    }
}

int check_char(){
    int h,a,r;
    int next;
    h=fgetc(fd);
    a=fgetc(fd);
    r=fgetc(fd);
    next=fgetc(fd);
    if(r=='r' && h=='h' && a=='a' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"char\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(r,fd);
        ungetc(a,fd);
        ungetc(h,fd);
        return 0;
    }
}

int check_if(){
    int f;
    int next;
    f=fgetc(fd);
    next=fgetc(fd);
    if(f=='f'  && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"if\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(f,fd);
        return 0;
    }
}

int check_integer(){
    int n,t,e1,g,e2,r;
    int next;
    n=fgetc(fd);
    t=fgetc(fd);
    e1=fgetc(fd);
    g=fgetc(fd);
    e2=fgetc(fd);
    r=fgetc(fd);
    if(n=='n' && t=='t' && e1=='e' && g=='g' && e2=='e' && r=='r' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"integer\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(r,fd);
        ungetc(e2,fd);
        ungetc(g,fd);
        ungetc(e1,fd);
        ungetc(t,fd);
        ungetc(n,fd);
        return 0;
    }
}

int check_return(){
    int e,t,u,r,n;
    int next;
    e=fgetc(fd);
    t=fgetc(fd);
    u=fgetc(fd);
    r=fgetc(fd);
    n=fgetc(fd);
    next=fgetc(fd);
    if(e=='e' && r=='r' && t=='t' && u=='u' && n=='n' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"return\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(n,fd);
        ungetc(r,fd);
        ungetc(u,fd);
        ungetc(t,fd);
        ungetc(e,fd);
        return 0;
    }
}

int check_boolean(){
    int o1,o2,l,e,a,n;
    int next;
    o1=fgetc(fd);
    o2=fgetc(fd);
    l=fgetc(fd);
    e=fgetc(fd);
    a=fgetc(fd);
    n=fgetc(fd);
    next=fgetc(fd);
    if(o1=='o' && o2=='o' && l=='l' && e=='e' && a=='a' && n=='n' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"boolean\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(n,fd);
        ungetc(a,fd);
        ungetc(e,fd);
        ungetc(l,fd);
        ungetc(o2,fd);
        ungetc(o1,fd);
        return 0;
    }
}

int check_else(){
    int l,s,e;
    int next;
    l=fgetc(fd);
    s=fgetc(fd);
    e=fgetc(fd);
    next=fgetc(fd);
    if(l=='l' && e=='e' && s=='s' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"else\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(e,fd);
        ungetc(s,fd);
        ungetc(l,fd);
        return 0;
    }
}


int check_print(){
    int r,i,n,t;
    int next;
    r=fgetc(fd);
    i=fgetc(fd);
    n=fgetc(fd);
    t=fgetc(fd);
    next=fgetc(fd);
    if( r=='r' && i=='i' && t=='t' && n=='n' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"print\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(t,fd);
        ungetc(n,fd);
        ungetc(i,fd);
        ungetc(r,fd);
        return 0;
    }
}

int check_string(){
    int t,r,i,n,g;
    int next;
    t=fgetc(fd);
    r=fgetc(fd);
    i=fgetc(fd);
    n=fgetc(fd);
    g=fgetc(fd);
    next=fgetc(fd);
    if(t=='t' && r=='r' && i=='i' && n=='n' && g=='g'  && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"string\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(g,fd);
        ungetc(n,fd);
        ungetc(i,fd);
        ungetc(r,fd);
        ungetc(t,fd);
        return 0;
    }
}

int check_void(){
    int o,i,d;
    int next;
    o=fgetc(fd);
    i=fgetc(fd);
    d=fgetc(fd);
    next=fgetc(fd);
    if(o=='o' && i=='i' &&  d=='d' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"void\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(d,fd);
        ungetc(i,fd);
        ungetc(o,fd);
        return 0;
    }
}


int check_for(){
    int o,r;
    int next;
    o=fgetc(fd);
    r=fgetc(fd);
    next=fgetc(fd);
    if(o=='o' && r=='r' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"for\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(r,fd);
        ungetc(o,fd);
        return 0;
    }
}


int check_function(){
    int u,n1,c,t,i,o,n2;
    int next;
    u=fgetc(fd);
    n1=fgetc(fd);
    c=fgetc(fd);
    t=fgetc(fd);
    i=fgetc(fd);
    o=fgetc(fd);
    n2=fgetc(fd);
    next=fgetc(fd);
    if(u=='u' && n1=='n' && c=='c' && t=='t' && i=='i' && o=='o' && n2=='n' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_keyword:%d:\"function\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(n2,fd);
        ungetc(o,fd);
        ungetc(i,fd);
        ungetc(t,fd);
        ungetc(c,fd);
        ungetc(n1,fd);
        ungetc(u,fd);
        return 0;
    }
}

int check_true(){
    int r,u,e;
    int next;
    r=fgetc(fd);
    u=fgetc(fd);
    e=fgetc(fd);
    next=fgetc(fd);
    if(r=='r' && u=='u' && e=='e' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_boolean:%d:\"true\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(e,fd);
        ungetc(u,fd);
        ungetc(r,fd);
        return 0;
    }
}

int check_false(){
    int a,l,s,e;
    int next;
    a=fgetc(fd);
    l=fgetc(fd);
    s=fgetc(fd);
    e=fgetc(fd);
    next=fgetc(fd);
    if(a=='a' && l=='l' && s=='s' && e=='e' && !(isalnum(next)) && !(next=='_')){
        fprintf(fo,"token_boolean:%d:\"false\"\n",num_line);
        ungetc(next,fd);
        return 1;
    }
    else{
        ungetc(next,fd);
        ungetc(e,fd);
        ungetc(s,fd);
        ungetc(l,fd);
        ungetc(a,fd);
        return 0;
    }
}


void scan(){
    int d;
    c = fgetc(fd);
    while(c==10 || c==9 || c==32 || c==13){
            if(c==10)
                num_line++;
            c=fgetc(fd);
    }
    if(c=='a'){
        if(check_array())
            return;
    }
    else if(c=='c'){
        if(check_char())
            return;
    }
    else if(c=='i'){
        if(check_if())
            return;
        else if(check_integer())
            return;
    }

    else if(c=='r'){
        if(check_return())
            return;
    }
    else if(c=='b'){
        if(check_boolean())
            return;
    }
    else if(c=='e'){
        if(check_else())
            return;
    }
    else if(c=='p'){
        if(check_print())
            return;
    }
    else if(c=='s'){
        if(check_string())
            return;
    }
    else if(c=='v'){
        if(check_void())
            return;
    }
    else if(c=='t'){
        if(check_true())
        return;
    }
    else if(c=='f'){
        if(check_for())
            return;
        else if(check_false())
            return;
        else if(check_function())
            return;
    }

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_')){
        fprintf(fo,"token_identifer:%d:\"%c",num_line,c);
        c=fgetc(fd);
        while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') || (c == '_')){
                    fprintf(fo,"%c",c);
                    c=fgetc(fd);
            }
        ungetc(c,fd);
        fprintf(fo,"\"\n");
    }
    else if(c >= '0' && c <= '9'){
        fprintf(fo,"token_integer:%d:\"%c",num_line,c);
        c=fgetc(fd);
        while(c >= '0' && c <= '9'){
            fprintf(fo,"%c",c);
            c=fgetc(fd);
        }
        ungetc(c,fd);
        fprintf(fo,"\"\n");
    }
    else if(c=='/'){
        c=fgetc(fd);
        if(c=='*')
            remove_comments();
        else if(c=='/'){
            remove_comment();
        }
        else{
            ungetc(c,fd);
            fprintf(fo,"token_operator:%d:\"%c\"\n",num_line,'/');
        }
    }
    else if(c=='&' || c=='|' || c=='=' || c=='+' || c=='-'){
        d=fgetc(fd);
        if(d==c){
            fprintf(fo,"token_operator:%d:\"%c%c\"\n",num_line,c,d);
        }
        else{
            fprintf(fo,"token_operator:%d:\"%c\"\n",num_line,c);
            ungetc(d,fd);
        }
    }
    else if(c=='*' || c=='^' || c=='%'){
        fprintf(fo,"token_operator:%d:\"%c\"\n",num_line,c);
    }
    else if(c=='(' ||  c==')' || c==';' || c==':' || c=='[' || c==']' || c=='{' || c=='}'){
        fprintf(fo,"token_seperator:%d:\"%c\"\n",num_line,c);
    }
    else if(c=='!'){
        c=fgetc(fd);
        if(c=='='){
            fprintf(fo,"token_operator:%d:\"%s\"\n",num_line,"!=");
        }
        else{
            fprintf(fo,"token_operator:%d:\"%c\"\n",num_line,'!');
            ungetc(c,fd);
        }
    }
    else if(c=='>' || c=='<'){
        d=fgetc(fd);
        if(d=='='){
            fprintf(fo,"token_operator:%d:\"%c%c\"\n",num_line,c,d);
        }
        else{
            fprintf(fo,"token_operator:%d:\"%c\"\n",num_line,c);
            ungetc(d,fd);
        }
    }
    else if(c=='"'){
        fprintf(fo,"token_string:%d:\"",num_line);
        c=fgetc(fd);
        while(c!='"'){
            fprintf(fo,"%c",c);
            c=fgetc(fd);
            if(c==92){
                c=fgetc(fd);
                if(c=='"'){
                    fprintf(fo,"\\\"");
                    c=fgetc(fd);
                }
                else{
                    fprintf(fo,"\\%c",c);
                    c=fgetc(fd);
                }
            }
        }
        fprintf(fo,"\"\n");
    }
    else if(c==39){
        fprintf(fo,"token_char:%d:\"",num_line);
        c=fgetc(fd);
        while(c!=39){
            fprintf(fo,"%c",c);
            c=fgetc(fd);
            if(c==92){
                c=fgetc(fd);
                if(c==39){
                    fprintf(fo,"\\\'");
                    c=fgetc(fd);
                }
                else{
                    fprintf(fo,"\\%c",c);
                }
            }
        }
    fprintf(fo,"\"\n");
    }
   // else{
   //     printf("%c \n",c);
   // }
}

int main()
{
    fd = fopen("program.c","r");
    fo = fopen("token.c","w");
    while(!feof(fd)){
        scan();
    }
    fclose(fo);
    fclose(fd);
    return 0;
}
