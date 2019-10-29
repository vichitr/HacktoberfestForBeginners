package main

import (
	"fmt"
)

func main() {
	size := 20
	stack := make([]int, 0)
	printPeek(stack)
	fmt.Println("Push operations:")
	for i := 0; i < size; i++ {
		stack = push(stack, i+1)
		printPeek(stack)
	}
	fmt.Println("Pop operations:")
	for i := 0; i < size; i++ {
		stack = pop(stack)
	}
}

func push(stack []int, value int) []int {
	newStack := make([]int, len(stack)+1)
	for i := 0; i < len(stack); i++ {
		newStack[i] = stack[i]
	}
	newStack[len(stack)] = value
	fmt.Println("Pushed: ", value)
	fmt.Println("After pushed: ", newStack)
	return newStack
}

func pop(stack []int) []int {
	printPeek(stack)
	if len(stack) > 0 {
		p := peek(stack)
		fmt.Println("Popped: ", p)
		newStack := stack[:len(stack)-1]
		fmt.Println("After popped: ", newStack)
		return newStack
	}
	return stack
}

func printPeek(stack []int) {
	if len(stack) == 0 {
		fmt.Println("Stack is empty now.")
	} else {
		fmt.Println("Peek:", peek(stack))
	}
}

func peek(stack []int) int {
	return stack[len(stack)-1]
}
