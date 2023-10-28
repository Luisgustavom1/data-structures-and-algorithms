package queue

type Queue[T any] struct {
	Value []T
}

func NewQueue[T any](values ...T) *Queue[T] {
	return &Queue[T]{
		Value: values,
	}
}

func (queue *Queue[T]) Enqueue(value ...T) bool {
	queue.Value = append(queue.Value, value...)

	return true
}

func (queue *Queue[T]) Dequeue() (value T, err error) {
	value = queue.Value[0]

	queueCopy := make([]T, len(queue.Value)-1)

	copy(queueCopy, queue.Value[1:])
	queue.Value = queueCopy

	return value, nil
}
