
public class Fact {
    public long ans; // The computed factorial value
    public Fact(/* Fact this */) {
        ans = 0; // no ans in stackframe, rewrite as this.ans = 0;
        // return this
    }
    // Computes factorial of n
    public void compute(/* Fact this, */ int n) {
        // Base case
        if(n<2) {
            ans = 1; // this.ans = 1
            return;
        }
        // Recursive case
        compute(n-1); // this.compute(n-1)
        ans = n * ans; // this.ans = n * this.ans
        // return;
    }

    public static void main(String[] args) {
        Fact f = new Fact();
        f.compute(3);
        System.out.println(f.ans);
    }
}

