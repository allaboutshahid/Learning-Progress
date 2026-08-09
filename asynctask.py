import asyncio
import random
from dataclasses import dataclass


@dataclass
class TaskResult:
    task_id: int
    success: bool
    result: str


async def process_task(task_id: int) -> TaskResult:
    delay = random.uniform(0.2, 1.0)
    await asyncio.sleep(delay)

    if random.random() < 0.1:
        return TaskResult(task_id, False, "Task failed")

    return TaskResult(
        task_id,
        True,
        f"Task completed in {delay:.2f}s"
    )


async def worker(
    queue: asyncio.Queue,
    results: list[TaskResult]
) -> None:
    while True:
        task_id = await queue.get()

        if task_id is None:
            queue.task_done()
            break

        try:
            result = await process_task(task_id)
            results.append(result)
            print(f"[{task_id}] {result.result}")
        finally:
            queue.task_done()


async def main() -> None:
    queue = asyncio.Queue()
    results: list[TaskResult] = []

    workers = [
        asyncio.create_task(worker(queue, results))
        for _ in range(5)
    ]

    for task_id in range(1, 21):
        await queue.put(task_id)

    await queue.join()

    for _ in workers:
        await queue.put(None)

    await asyncio.gather(*workers)

    successful = sum(result.success for result in results)

    print(f"\nCompleted: {successful}/{len(results)}")


if __name__ == "__main__":
    asyncio.run(main())