import { describe, it, expect } from 'vitest'
import { Queue } from '../code/queue'

describe("Queue implementation", () => {
  const testCases = [
    {
      description: "Should initialize a empty queue",
      expected: true,
      act: (queue: Queue) => queue.isEmpty(),
    },
    {
      description: "Should return null when dequeue a empty queue",
      expected: null,
      act: (queue: Queue) => {
        queue.enqueue(1);
        queue.enqueue(5);
        queue.enqueue(4);
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        return queue.dequeue();
      },
    },
    {
      description: "Should return correct value when dequeue",
      expected: 5,
      act: (queue: Queue) => {
        queue.enqueue(5);
        queue.enqueue(3);
        queue.enqueue(1);
        return queue.dequeue();
      },
    },
    {
      description: "Should return correct value when dequeue",
      expected: 5,
      act: (queue: Queue) => {
        queue.enqueue(5);
        queue.enqueue(3);
        queue.enqueue(1);
        return queue.dequeue();
      },
    },
    {
      description: "Should return correct size queue",
      expected: 3,
      act: (queue: Queue) => {
        queue.enqueue(5);
        queue.enqueue(3);
        queue.enqueue(1);
        return queue.size();
      },
    },
    {
      description: "Should return correct queue",
      expected: [8, 9, 1],
      act: (queue: Queue) => {
        queue.enqueue(1);
        queue.enqueue(6);
        queue.dequeue();
        queue.dequeue();
        queue.enqueue(8);
        queue.enqueue(9);
        queue.enqueue(1);
        return queue.getQueueAsArray();
      },
    }
  ]
  
  it.each(testCases)(
    '$description', ({ act, expected }) => {
      const queue = new Queue();
      expect(act(queue)).toStrictEqual(expected)
    }
  )
});
