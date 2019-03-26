FROM alpine:latest

RUN apk add --no-cache openntpd

ENV TZ Europe/Berlin

COPY ntpd.conf /etc/ntpd.conf

EXPOSE 123/udp

HEALTHCHECK CMD ntpctl -s  status || exit 1

ENTRYPOINT ["/usr/sbin/ntpd", "-v", "-d", "-s"]
