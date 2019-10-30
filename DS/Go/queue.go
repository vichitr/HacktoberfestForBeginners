package main

import (
	"fmt"
)

func main() {
	size := 20
	queue := make([]int, 0)
	printPeek(queue)
	fmt.Println("Push operations:")
	for i := 0; i < size; i++ {
		queue = enQueue(queue, i+1)
		printPeek(queue)
	}
	fmt.Println("Pop operations:")
	for i := 0; i < size; i++ {
		queue = deQueue(queue)
	}
}

func enQueue(queue []int, value int) []int {
	newQueue := make([]int, len(queue)+1)
	for i := 0; i < len(queue); i++ {
		newQueue[i] = queue[i]
	}
	newQueue[len(queue)] = value
	fmt.Println("Enqueue: ", value)
	fmt.Println("After enqueue: ", newQueue)
	return newQueue
}

func deQueue(queue []int) []int {
	printPeek(queue)
	if len(queue) > 0 {
		p := peek(queue)
		fmt.Println("Dequeue: ", p)
		newQueue := queue[1:len(queue)]
		fmt.Println("After dequeue: ", newQueue)
		return newQueue
	}
	return queue
}

func printPeek(queue []int) {
	if len(queue) == 0 {
		fmt.Println("Queue is empty now.")
	} else {
		fmt.Println("Peek:", peek(queue))
	}
}

func peek(queue []int) int {
	return queue[0]
}
