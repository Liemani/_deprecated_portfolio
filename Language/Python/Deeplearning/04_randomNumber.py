import numpy as np


def random_number():
    import matplotlib.pyplot as plt
    import seaborn as sns
    sns.set()
    import warnings
    warnings.simplefilter("ignore", UserWarning)

    uniform = np.random.uniform(0,1,1000)

    normal = np.random.normal(0,1,1000)

    ax = sns.distplot(uniform, label="Uniform Distribution")
    bs = sns.distplot(normal, label="Normal Distribution")
    legend = plt.legend()
    plt.show()
