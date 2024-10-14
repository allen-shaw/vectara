package client

import "github.com/allen-shaw/vectara/client/internal"

type Client interface {
}

func New() (Client, error) {
	c, err := internal.NewClient()
	return c, err
}
