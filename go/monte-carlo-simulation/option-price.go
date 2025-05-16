package main

import (
	"math/rand"
	"time"
)

func main() {
	rand := rand.New(rand.NewSource(time.Now().UnixNano()))
}
