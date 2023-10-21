import java.util.*;
public class validparan
{
    private stack st;

    class stack
    {
        private Listnode top;
        private int length;
        class Listnode 
        {
            private char data;
            private Listnode next;
            public Listnode()
            {
                this.next = null;
            }
            public Listnode(char val)
            {
                this.data = val;
                this.next = null;
            }
        }

        stack()
        {
            top = null;
            length = 0;
        }
        public boolean isEmpty()
        {
            if(top == null)
                return true;
            else 
                return false;
        }
        public void push(char val)
        {
            Listnode temp = new Listnode(val);
            if(!isEmpty())
            {
                temp.next = top;
            }
            top = temp;
            length++;
        }
        public char pop()
        {
            if(isEmpty())
                return '-';
            else 
            {
                char res = top.data;
                top = top.next;
                length--;
                return res;
            }
        }
        public void peek()
        {
            if(!isEmpty())
            {
                System.out.println(top.data);
            }
        }
    }

    public validparan()
    {
        st = new stack();
    }

    public boolean validparan(String s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            if(c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if( st.top == null)
                {
                    return false;
                }
                else if((c == ')' && st.top.data == '(') || (c == '}' && st.top.data == '{') || (c == ']' && st.top.data == '['))
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
            return st.isEmpty();
    }
    public static void main(String[] args)
    {
        validparan oss = new validparan();
        String s1 = "{[)]}";
        System.out.println(oss.validparan(s1));
    }
}
