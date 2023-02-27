package queue

import "errors"

type Queue struct {
	Value []int
}

func NewQueue() *Queue {
	return &Queue{}
}

func (queue *Queue) Enqueue(value int) int {
	queue.Value = append(queue.Value, value)

	return value
}

func (queue *Queue) Dequeue() (value int, err error) {
	if len(queue.Value) == 0 {
		return -1, errors.New("queue is empty")
	}

	value = queue.Value[0]

	queueCopy := make([]int, len(queue.Value)-1)

	copy(queueCopy, queue.Value[1:])
	queue.Value = queueCopy

	return value, nil
}
