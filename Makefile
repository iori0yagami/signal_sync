CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVERB = server_bonus
CLIENTB = client_bonus

SRCSSS = server.c utils.c utils2.c
SRCSCC = client.c utils.c utils2.c

BONUS_SRCSSS = server_bonus.c utils.c utils2.c
BONUS_SRCSCC = client_bonus.c utils.c utils2.c

OBJSSS = $(SRCSSS:.c=.o)
OBJCC = $(SRCSCC:.c=.o)

BONUS_OBJSSS = $(BONUS_SRCSSS:.c=.o)
BONUS_OBJCC = $(BONUS_SRCSCC:.c=.o)

all: $(SERVER) $(CLIENT)

bonus: $(SERVERB) $(CLIENTB)

$(SERVER): $(OBJSSS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(OBJCC)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVERB): $(BONUS_OBJSSS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENTB): $(BONUS_OBJCC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJSSS) $(OBJCC) $(BONUS_OBJSSS) $(BONUS_OBJCC)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVERB) $(CLIENTB)

re: fclean all
