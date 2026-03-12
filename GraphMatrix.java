import java.util.Scanner;

public class GraphMatrix {
    public static void main(String[] args) {
        
        int v,e,x,y;

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of vertices: ");
        v = sc.nextInt();
        sc.nextLine();

        System.out.println("Enter number of edges: ");
        e = sc.nextInt();
        sc.nextLine();

        int[][] adjMatrix = new int[v][v];

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                adjMatrix[i][j] = 0;
            }
        }

        for(int i=0;i<e;i++){
            System.out.println("Enter 2 nodes that are adjacent from path 1 to 2: ");

            x = sc.nextInt();
            y = sc.nextInt();

            adjMatrix[x][y] = 1;
            adjMatrix[y][x] = 1;
        }

        System.out.println("Adjacency Matrix: ");

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
