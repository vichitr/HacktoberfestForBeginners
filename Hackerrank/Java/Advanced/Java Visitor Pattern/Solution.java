/* This is the most annoying HackerRank challenge I've seen yet. */

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.ArrayList;
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import java.util.ArrayList;
import java.util.Scanner;

enum Color {
    RED, GREEN
}

abstract class Tree {

    private int value;
    private Color color;
    private int depth;

    public Tree(int value, Color color, int depth) {
        this.value = value;
        this.color = color;
        this.depth = depth;
    }

    public int getValue() {
        return value;
    }

    public Color getColor() {
        return color;
    }

    public int getDepth() {
        return depth;
    }

    public abstract void accept(TreeVis visitor);
}

class TreeNode extends Tree {

    private ArrayList<Tree> children = new ArrayList<>();

    public TreeNode(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitNode(this);

        for (Tree child : children) {
            child.accept(visitor);
        }
    }

    public void addChild(Tree child) {
        children.add(child);
    }
}

class TreeLeaf extends Tree {

    public TreeLeaf(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitLeaf(this);
    }
}

abstract class TreeVis
{
    public abstract int getResult();
    public abstract void visitNode(TreeNode node);
    public abstract void visitLeaf(TreeLeaf leaf);

}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class SumInLeavesVisitor extends TreeVis {
    private int result = 0;

    public int getResult() {
        return result;
    }

    public void visitNode(TreeNode node) {
    }

    public void visitLeaf(TreeLeaf leaf) {
        result += leaf.getValue();
    }
}


class ProductOfRedNodesVisitor extends TreeVis {
    private long result = 1;
    private final int M = 1000000007;

    public int getResult() {
        return (int) result;
    }

    public void visitNode(TreeNode node) {
        if(node.getColor().equals(Color.RED)) {
            result = (result * node.getValue()) % M;
        }
    }

    public void visitLeaf(TreeLeaf leaf) {
        if(leaf.getColor().equals(Color.RED)) {
            result = (result * leaf.getValue()) % M;
        }
    }
}


class FancyVisitor extends TreeVis {
    private int evenDepthNonLeafSum = 0;
    private int greenLeafSum = 0;

    public int getResult() {
        return Math.abs(evenDepthNonLeafSum - greenLeafSum);
    }

    public void visitNode(TreeNode node) {
        if(node.getDepth() % 2 == 0)
            evenDepthNonLeafSum += node.getValue();
    }

    public void visitLeaf(TreeLeaf leaf) {
        if(leaf.getColor().equals(Color.GREEN))
            greenLeafSum += leaf.getValue();
    }
}

/* Thanks to HackerRank users romullogirardi and RodneyShag for portions
 * of this solution. What a very, very annoying challenge this is. */
public class Solution {
    private static int [] values;
    private static Color [] colors;
    private static HashMap<Integer, HashSet<Integer>> map;

    public static Tree solve() {
        Scanner scan = new Scanner(System.in);
        int numNodes = scan.nextInt();

        values = new int[numNodes];
        for (int i = 0; i < numNodes; i++) {
            values[i] = scan.nextInt();
        }

        colors = new Color[numNodes];
        for (int i = 0; i < numNodes; i++) {
            colors[i] = scan.nextInt() == 0 ? Color.RED : Color.GREEN;
        }

        map = new HashMap<>(numNodes);
        for (int i = 0; i < numNodes - 1; i++) {
            int u = scan.nextInt();
            int v = scan.nextInt();

            HashSet<Integer> uNeighbors = map.get(u);
            if (uNeighbors == null) {
                uNeighbors = new HashSet<>();
                map.put(u, uNeighbors);
            }
            uNeighbors.add(v);

            HashSet<Integer> vNeighbors = map.get(v);
            if (vNeighbors == null) {
                vNeighbors = new HashSet<>();
                map.put(v, vNeighbors);
            }
            vNeighbors.add(u);
        }
        scan.close();

        if (numNodes == 1) {
            return new TreeLeaf(values[0], colors[0], 0);
        }

        TreeNode root = new TreeNode(values[0], colors[0], 0);
        addChildren(root, 1);
        return root;
    }

    private static void addChildren(TreeNode parent, Integer parentNum) {
        for (Integer treeNum : map.get(parentNum)) {
            map.get(treeNum).remove(parentNum);

            HashSet<Integer> grandChildren = map.get(treeNum);
            boolean childHasChild = (grandChildren != null
                                     && !grandChildren.isEmpty());
            Tree tree;
            if (childHasChild) {
                tree = new TreeNode(values[treeNum - 1],
                                    colors[treeNum - 1],
                                    parent.getDepth() + 1);
            } else {
                tree = new TreeLeaf(values[treeNum - 1],
                                    colors[treeNum - 1],
                                    parent.getDepth() + 1);
            }
            parent.addChild(tree);

            if (tree instanceof TreeNode) {
                addChildren((TreeNode) tree, treeNum);
            }
        }
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */

    public static void main(String[] args) {
          Tree root = solve();
        SumInLeavesVisitor vis1 = new SumInLeavesVisitor();
          ProductOfRedNodesVisitor vis2 = new ProductOfRedNodesVisitor();
          FancyVisitor vis3 = new FancyVisitor();

          root.accept(vis1);
          root.accept(vis2);
          root.accept(vis3);

          int res1 = vis1.getResult();
          int res2 = vis2.getResult();
          int res3 = vis3.getResult();

          System.out.println(res1);
         System.out.println(res2);
        System.out.println(res3);
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
