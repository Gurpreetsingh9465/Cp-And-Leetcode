int findStep(int n) 
{ 
    if (n == 1 || n == 0)  
        return 1; 
    else if (n == 2)  
        return 2; 
      
    else
        return findStep(n - 3) +  
            findStep(n - 2) + 
            findStep(n - 1);  
} 
}; 
int main() {
  char *str1 = "Hi", *str2 = "Bye";
  fun1(str1, str2);
  printf("%s %s", str1, str2);
  fun2(&str1, &str2);
  printf("%s %s", str1, str2);
  return 0;
}