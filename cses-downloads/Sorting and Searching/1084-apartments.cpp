def find_maximum_applicants(n, m, k, applicants, apartments):
    # Sort the desired apartment sizes and the actual apartment sizes
    applicants.sort()
    apartments.sort()

    i, j = 0, 0
    matches = 0
    
    # Use two pointers to find the maximum number of applicants that can get an apartment
    while i < n and j < m:
        if apartments[j] < applicants[i] - k:
            # Apartment is too small, move to the next apartment
            j += 1
        elif apartments[j] > applicants[i] + k:
            # Apartment is too large, move to the next applicant
            i += 1
        else:
            # Apartment fits the applicant, assign it and move both pointers
            matches += 1
            i += 1
            j += 1

    return matches

# Example usage:
n, m, k = map(int, input().split())
applicants = list(map(int, input().split()))
apartments = list(map(int, input().split()))

result = find_maximum_applicants(n, m, k, applicants, apartments)
print(result)
