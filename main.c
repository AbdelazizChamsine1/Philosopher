int main(int argc, char **argv)
{
    t_data data;

    if (argc != 5 && argc != 6)
        return (printf("Invalid arguments\n"), 1);
    if (init_data(&data, argc, argv) != 0)
        return (printf("Initialization failed\n"), 1);
    if (create_threads(&data) != 0)
        return (printf("Thread creation failed\n"), 1);
    join_threads(&data);
    cleanup(&data);
    return (0);
}
