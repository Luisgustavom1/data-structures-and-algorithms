package queue

import (
	"errors"
)

type Queue struct {
	Value []string
}

func NewQueue(values ...string) *Queue {
	return &Queue{
		Value: values,
	}
}

func (queue *Queue) Enqueue(value ...string) bool {
	queue.Value = append(queue.Value, value...)

	return true
}

func (queue *Queue) Dequeue() (value string, err error) {
	if len(queue.Value) == 0 {
		return "", errors.New("queue is empty")
	}

	value = queue.Value[0]

	queueCopy := make([]string, len(queue.Value)-1)

	copy(queueCopy, queue.Value[1:])
	queue.Value = queueCopy

	return value, nil
}
