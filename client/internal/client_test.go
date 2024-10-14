package internal

import (
	"context"
	"log"
	"testing"
	"time"

	pb "github.com/allen-shaw/vectara/proto"
	"google.golang.org/grpc"
)

func Test_Client(t *testing.T) {
	addr := "127.0.0.1:50051"

	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()

	cctx, ccancel := context.WithTimeout(ctx, 2*time.Second)
	defer ccancel()

	conn, err := grpc.DialContext(cctx, addr, grpc.WithInsecure())
	if err != nil {
		panic(err)
	}

	cc := pb.NewGreeterClient(conn)
	reply, err := cc.SayHello(cctx, &pb.HelloRequest{Name: "allen"})
	if err != nil {
		panic(err)
	}

	log.Println("new client succ", reply.Message)

}
